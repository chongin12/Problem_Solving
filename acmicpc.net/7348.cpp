#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        vector<pii> v;
        for(int i=0; i<N; ++i){
            int s, t; cin>>s>>t;
            s=(s-1)/2;
            t=(t-1)/2;
            v.push_back({min(s,t),max(s,t)});
        }
        sort(v.begin(), v.end());
        vector<bool> chk(N, 0);
        int cnt=0;
        int res=0;
        while(1){
            if(cnt>=N) break;
            res++;
            pii prev={-1,-1};
            for(int i=0; i<N; ++i){
                if(chk[i]) continue;
                if(prev.second<v[i].first){
                    prev=v[i];
                    cnt++;
                    chk[i]=true;
                }
            }
        }
        cout << res*10 << '\n';
    }
}