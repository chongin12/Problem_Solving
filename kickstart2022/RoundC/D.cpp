#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll MOD = 1000000007;
map<string, pair<ll,ll> > m;
pair<ll,ll> add(pair<ll,ll> a, pair<ll,ll> b){
    return {(a.first+b.first)%MOD,(a.second+b.second)%MOD};
}
bool isPal(string str){
    int sz=str.size()/2;
    bool flag=true;
    for(int i=0; i<=sz; ++i){
        if(str[i]!=str[str.size()-1-i]) flag=false;
    }
    return flag;
}
ll gcd_(ll a, ll b){
    if(b==0) return a;
    return gcd_(b, a%b);
}
pair<ll,ll> f(string str){ // {리프노드개수, 사탕의 개수}
    pair<ll,ll> ret(0,0);
    if(str.size()==0){
        return {1,1};
    }
    else if(str.size()==1){
        return {1,2};
    }
    else if(m.find(str)!=m.end()){
        ret = m[str];
    }
    else{
        string l=str, r="";
        for(int i=str.size()-1; i>=0; --i){
            l.pop_back();
            ret=add(ret, f(l+r));
            r=str[i]+r;
        }
    }
    if(isPal(str)) ret.second=(ret.first+ret.second)%MOD;
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        ll N; cin>>N;
        string str; cin>>str;
        m.clear();
        pair<ll,ll> res = f(str);
        ll bunmo = res.first;
        ll bunza = res.second;
        if(isPal(str)) bunza -= bunmo;
        if(bunza<0) bunza+=MOD;
        ll g=gcd_(bunmo,bunza);
        bunmo/=g;
        bunza/=g;
        ll E;
        if(bunmo==1) E=bunza;
        else{
            while(1){
                if(bunza%bunmo==0){
                    E=bunza/bunmo;
                    break;
                }
                bunza+=MOD;
            }
        }
        cout << "Case #"<<t<<": "<<E << '\n';
    }
}