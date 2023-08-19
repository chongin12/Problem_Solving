#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll T; cin>>T;
    for(ll t=1; t<=T; ++t){
        cout << "Case #" << t << "\n";
        ll N; cin>>N;
        vector<ll> stk;
        vector<ll> couple(N, -1), cont(N);
        vector<pair<ll,ll>> nested(N); // {개수, 짝}
        string str; cin>>str;
        for(ll i=0; i<N; ++i){
            if(stk.empty()){
                stk.push_back(i);
            }
            else if((str[stk.back()]=='{' && str[i]=='}') || (str[stk.back()]=='(' && str[i]==')')){
                couple[stk.back()]=i;
                couple[i]=stk.back();
                stk.pop_back();
                if(couple[i]==i-1){
                    nested[i]={1,couple[i]};
                    cont[i]=1;
                }
                // 중첩 검사
                else if(couple[i-1]==couple[i]+1){
                    if(nested[i-1].second==couple[i]+1){
                        nested[i]={nested[i-1].first+1, couple[i]};
                        nested[i-1].first=0;
                    }
                    else{
                        nested[i]={1, couple[i]};
                    }
                    cont[i]=1;
                }
                // 연속 검사
                if(couple[i]-1>=0 && couple[couple[i]-1]!=-1){
                    cont[i]=cont[couple[i]-1]+1;
                    cont[couple[i]-1]=0;
                    couple[i]=couple[couple[i]-1];
                }
            }
            else{
                stk.push_back(i);
            }
        }
        // for(ll i=0; i<N; ++i){
        //     cout << "\ncouple["<<i<<"]="<<couple[i]<<'\n';
        //     cout << "nested["<<i<<"]= ("<<nested[i].first << ", " << nested[i].second << ")\n";
        //     cout << "cont["<<i<<"]="<<cont[i]<<'\n';
        // }
        ll cur=N-1;
        ll res=0;
        for(ll i=0; i<N; ++i){
            if(nested[i].first>0){
                res+=nested[i].first;
            }
            if(cont[i]>1){
                res+=cont[i]*(cont[i]+1)/2-cont[i];
            }
        }
        // nested 개수 세기 (자기 자신 빼고)
        // while(cur>0){
        //     if(couple[cur]!=-1){
        //         res+=nested[cur].first-1;
        //         // cur=nested[cur].second-1;
        //     }
        //     cur-=1;
        // }
        // cout << "중간점검 : " << res << '\n';
        // cont 개수 세기 (자기 자신 포함)
        // cur=N-1;
        // while(cur>0){
        //     if(couple[cur]!=-1){
        //         ll k=cont[cur];
        //         res+=k*(k+1)/2;
        //         // cur=couple[cur]-1;
        //     }
        //     cur-=1;
        // }
        cout << res << '\n';
    }
}