#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct node {
    ll cnt, rot, lastidx; // dp값, 회전 횟수, 나머지(종료 시점)
    node():cnt(0),rot(0),lastidx(0){}
    node(ll cnt, ll rot, ll lastidx):cnt(cnt),rot(rot),lastidx(lastidx){}
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll T; cin>>T;
    for(ll t=1; t<=T; ++t){
        cout << "Case #" << t << "\n";
        vector<ll> v;
        ll N, K; cin>>N>>K;
        vector<node> dp(N+1);
        vector<node> cache(N+1); // 1점 먹으려면 어디까지 가야하는지
        for(ll i=0; i<N; ++i){
            ll a; cin>>a; v.push_back(a);
            dp[i] = {0,0,i-1};
        }
        dp[N]={0,0,N-1};
        for(ll i=N-1; i>=0; --i){
            ll cnt=0, lastidx=i-1; // lastidx + 1부터 탐색해야 함.
            ll phase=0, tempsum=0;
            ll j;
            for(j=i; ; ++j){
                tempsum+=v[j%N];
                // cout << "j : " << j << '\n';
                // cout << "phase : " << phase << ", tempsum : " << tempsum << "\n";
                if(phase==0){
                    if(tempsum==5){
                        phase=1;
                        tempsum=0;
                    }
                    else if(tempsum==10){
                        phase=3;
                        tempsum=0;
                    }
                    else if(tempsum>=21){
                        cnt+=1;
                        lastidx=j;
                        break;
                    }
                }
                else if(phase==1){
                    if(tempsum==3){
                        phase=2;
                        tempsum=0;
                    }
                    else if(tempsum>=12) {
                        cnt+=1;
                        lastidx=j;
                        break;
                    }
                }
                else if(phase==2){
                    if(tempsum>=4){
                        cnt+=1;
                        lastidx=j;
                        break;
                    }
                }
                else if(phase==3){
                    if(tempsum>=7){
                        cnt+=1;
                        lastidx=j;
                        break;
                    }
                }
            }
            cache[i]={1, (j-i)/N, j%N};
            // cout << "cache["<<i<<"]=("<<cache[i].cnt<<", "<<cache[i].rot<<", "<<cache[i].lastidx << ")\n";
        }
        for(ll i=N-1; i>=0; --i){
            if(cache[i].rot || cache[i].lastidx < i){
                dp[i]={0, 0, i-1};
            }
            else{
                node temp = dp[cache[i].lastidx+1];

                dp[i]={temp.cnt+1, 0, temp.lastidx};
            }
        }
        ll res=0;
        ll cur=0;
        while(K>0){
            if(dp[cur].cnt==0){
                K-=cache[cur].rot;
                if(cache[cur].lastidx<cur) K-=1;
                cur=cache[cur].lastidx+1;
                if(cur==N){
                    K-=1;
                    cur=0;
                }
                res+=1;
            }
            else{
                res+=dp[cur].cnt;
                cur=dp[cur].lastidx+1;
                if(cur==N){
                    K-=1;
                    cur=0;
                }
            }
        }
        if(K<0 || (K==0 && cur>0)) res--;
        cout << res << '\n';
    }
}