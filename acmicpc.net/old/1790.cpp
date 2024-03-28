#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll res=0,k,N;
void f(ll depth, ll nums, ll start){
    if(nums<=0) return;
    // cout << depth << ", " << k << ", " << nums << '\n';
    for(ll i=start; i<=9; ++i){
        // cout << "i : " << i << ", k : " << k << '\n';
        if(k<=nums*depth){
            res=res*10+i;
            f(depth,nums/10,0);
            return;
        }
        else{
            k-=nums*depth;
        }
    }
}
int main(){
    cin>>N>>k;
    for(ll i=1,nums=9;;++i,nums*=10){
        // i자리 수
        if(k<=i*nums){
            f(i,nums/9,1);
            break;
        }
        else k-=i*nums;
    }
    if(res>N){
        cout << "-1\n";
        return 0;
    }
    // cout << "res : " << res << ",  k : " << k << '\n';
    vector<ll> v;
    while(res>0){
        v.push_back(res%10);
        res/=10;
    }
    cout << v[v.size()-k] << '\n';
}
/*
1 ~ 9 : 9개
10 ~ 99 : 90개
100 ~ 999 : 900개 
*/