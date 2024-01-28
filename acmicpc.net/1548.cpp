#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    int res=min(N,2);
    for(int i=0; i<(int)v.size()-2; ++i){
        for(int j=0; j<(int)v.size()-i-2; ++j){
            if(v[j]+v[j+1]>v[v.size()-1-i]){
                res=max(res,(int)v.size()-i-j);
            }
        }
    }
    cout << res << '\n';
}