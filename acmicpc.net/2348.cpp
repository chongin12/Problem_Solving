#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
ll toNum(ll start, ll end){
    ll ret=0;
    if(end>=s.size()) return 0;
    if(start>end) return 0;
    if(s[start]=='0') return 0;
    if(end-start+1>=12) return 0;
    for(ll i=start; i<=end; ++i){
        ret=ret*10+s[i]-'0';
    }
    if(ret>=1000000000) return 0;
    return ret;
}
ll len(ll k){
    return to_string(k).size();
}
bool isAccept(ll idx, ll k){ // idx부터 k를 accept할 수 있는지?
    if(k>=1000000000) return false;
    string str = to_string(k);
    for(ll i=0; i<str.size(); ++i){
        if(idx+i>=s.size()) return false;
        if(s[idx+i]!=str[i]) return false;
    }
    return true;
}
int main(){
    cin>>s;
    ll res=1e18;
    for(ll i=1; i<=10; ++i){
        // 첫 번째 숫자의 길이가 i일 때
        ll num1 = toNum(0, i-1);
        if(!num1) break;
        for(ll j=i; j<=10; ++j){
            ll idx=i;
            ll num2 = toNum(idx, idx+j-1);
            // cout << "num1 : " << num << '\n';
            // cout << "num2 : " << num2 << '\n';
            if(!num2) break;
            idx+=j;
            vector<ll> v;
            v.push_back(num1);
            v.push_back(num2);
            ll d = num2-num1;
            if(d<=0) continue;
            while(idx<s.size()){
                ll temp = toNum(idx, s.size()-1);
                if(temp) {
                    // cout << "temp : " << temp << '\n';
                    if(temp>v.back() && temp%v.back()==0){
                        res=min(res,temp/v.back());
                    }
                }

                // cout << "isAccept("<<idx<<", "<<v.back()+d<<")" << " : " << isAccept(idx, v.back()+d) << '\n';
                ll kk = v.back()+d;
                if(isAccept(idx, kk)){
                    idx+=len(kk);
                    v.push_back(kk);
                } else {
                    break;
                }
            }
        }
    }
    if(res==1e18) cout << "0\n";
    else cout << res << '\n';
}