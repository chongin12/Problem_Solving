#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, K; cin>>N>>K;
    vector<int> v, nums;
    int res=0;
    for(int i=0; i<K; ++i){
        int a; cin>>a; v.push_back(a); nums.push_back(a);
        if(N>=a) res=max(res,a);
    }
    for(int i=2; i<=8; ++i){
        vector<int> temp;
        for(int j=0; j<v.size(); ++j){
            for(int k=0; k<K; ++k){
                temp.push_back(v[j]*10+nums[k]);
                if(N>=temp.back()) res=max(res,temp.back());
            }
        }
        v=temp;
    }
    cout << res << '\n';
}