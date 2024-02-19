#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    int res=0;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<N; ++i){
        if(i+1>v[i]){
            res=i+1;
            break;
        }
    }
    cout << res << '\n';
}