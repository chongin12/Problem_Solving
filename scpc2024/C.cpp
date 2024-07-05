#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
vector<ll> arr[300001];
vector<ll> hubo;
void init() {
    for(ll i=0; i<300001; ++i) arr[i].clear();
    hubo.clear();
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll T; cin>>T;
    for(ll t=1; t<=T; ++t){
        cout << "Case #" << t << endl;
        init();
        ll N; cin>>N;
        for(ll i=0; i<N+1; ++i){
            ll a,b ;cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
            if(arr[a].size()>=3){
                for(int j=0; j<3; ++j){
                    if(arr[arr[a][j]].size()>=3){
                        hubo.push_back(a);
                        hubo.push_back(arr[a][j]);
                    }
                }
            }
            else if(arr[b].size()>=3){
                for(int j=0; j<3; ++j){
                    if(arr[arr[b][j]].size()>=3){
                        hubo.push_back(b);
                        hubo.push_back(arr[b][j]);
                    }
                }
            }
        }
        ll cur=arr[hubo[0]][0];
        if(cur==hubo[1]) cur=arr[hubo[0]][1];
        ll prev=hubo[0];
        ll cnt=1;
        while(cur!=hubo[1]){
            ll nxt = arr[cur][0];
            for(int i=1; i<arr[cur].size(); ++i){
                if(nxt==prev) nxt=arr[cur][i];
            }
            if(nxt==prev) nxt = arr[cur][1];
            prev=cur;
            cur=nxt;
            cnt++;
        }
        ll spare = N-cnt;
        cout << (cnt*(cnt-1)/2)+(spare*(spare-1)/2) << endl;
    }
}