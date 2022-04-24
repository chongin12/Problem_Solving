#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
vector<ll> v,res;
bool isEnd=false;
ll target;
void init(){
    v.clear();
    res.clear();
    isEnd=false;
}
void dfs(int idx, ll sum){
    if(isEnd) return;
    if(target<sum) return;
    if(binary_search(v.begin(), v.begin()+idx, target-sum)){
        res.push_back(target-sum);
        isEnd=true;
    }
    else{
        dfs(idx-1, sum);
        res.push_back(v[idx]);
        dfs(idx-1, sum+v[idx]);
        if(isEnd) return;
        res.pop_back();
    }
}
int main(){
    int T; cin>>T;
    while(T--){
        ll N;
        init();
        scanf("%lld", &N);
        target=0;
        for(ll i=0; i<N; ++i){
            v.push_back(i+1);
            target+=(i+1);
            if(i) printf(" ");
            printf("%lld", i+1);
        }
        printf("\n");
        fflush(stdout);
        for(ll i=0; i<N; ++i){
            ll a;
            scanf("%lld", &a);
            v.push_back(a);
            target+=a;
        }
        target/=2;
        sort(v.begin(), v.end());
        res.push_back(v[2*N-1]);
        dfs(2*N-1, v[2*N-1]);
        for(int i=0; i<res.size(); ++i){
            if(i) printf(" ");
            printf("%lld", res[i]);
        }
        printf("\n");
        fflush(stdout);
    }
}