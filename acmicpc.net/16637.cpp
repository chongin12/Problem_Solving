#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll toll(char op){
    if(op=='+') return -2;
    if(op=='-') return -3;
    return -4;
}
ll toOp(ll i){
    if(i==-2) return '+';
    if(i==-3) return '-';
    return '*';
}
ll res=-987654321987654;
int main(){
    ll N; cin>>N;
    string str; cin>>str;
    ll ops=N/2;
    for(ll i=0; i<(1<<ops); ++i){
        vector<ll> v;
        for(ll j=0; j<ops; ++j){
            if(i&(1<<j)) v.push_back(1);
            else v.push_back(0);
        }
        bool flag=true;
        for(ll j=1; j<ops; ++j){
            if(v[j]==1 && v[j-1]==1) flag=false;
        }
        if(!flag) continue;

        // for(auto it:v) cout << it << " ";
        // cout << '\n';
        
        vector<ll> st;
        st.push_back(str[0]-'0');
        for(ll j=1; j<N; j+=2){
            if(v[j/2]){
                auto cur = st.back(); st.pop_back();
                if(str[j]=='+') st.push_back(cur+(str[j+1]-'0'));
                if(str[j]=='-') st.push_back(cur-(str[j+1]-'0'));
                if(str[j]=='*') st.push_back(cur*(str[j+1]-'0'));
            }
            else{
                st.push_back(toll(str[j]));
                st.push_back(str[j+1]-'0');
            }
        }
        ll num=st[0];
        for(ll j=1; j<st.size(); j+=2){
            if(st[j]==-2) num=num+st[j+1];
            if(st[j]==-3) num=num-st[j+1];
            if(st[j]==-4) num=num*st[j+1];
        }
        // cout << " = " << num << '\n';
        res=max(res,num);
    }
    cout << res << '\n';
}