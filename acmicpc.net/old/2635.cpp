#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    vector<int> res;
    for(int i=0; i<=N; ++i){
        int cnt=0;
        vector<int> v;
        int b=i;
        v.push_back(N);
        while(b>=0){
            v.push_back(b);
            b=v[v.size()-2]-v.back();
        }
        if(res.size()<v.size()) res=v;
    }
    cout << res.size() << '\n';
    for(auto it:res){
        cout << it << ' ';
    }
    cout << '\n';
}