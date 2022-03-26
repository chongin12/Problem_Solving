#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll arr[11];
//vector<int> G[11];
ll res=0;
ll N, M, K;
void dfs(ll x, ll money, ll ju, ll dept){
    if(x>=N) {
        if(ju==0) res=max(res, money);
        return;
    }
    //1. 여기서 팔지 않는다.
    dfs(x+1, money, ju, dept);
    //2. 여기서 판다.
    money=money+arr[x]*ju;
    ju=0;
    //2-0. 여기서 튄다.
    res=max(res, money);
    money=money-dept;
    dept=0;
    if(money<=0) {
        return;
    }
    //2-1. 여기서 바로 사지 않는다.
    dfs(x+1, money, ju, dept);
    //2-2. 여기서 바로 산다.
    if(dept==0){
        dept=money*K;
        money=money+dept;
        ju=money/arr[x];
        money=money-ju*arr[x];
        if(ju==0) {
            money-=dept;
            dept=0;
        }
        dfs(x+1, money, ju, dept);
    }
    return;
}
int main(){
    cin>>N>>M>>K;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    dfs(0, M, 0, 0);
    cout << res << '\n';
}