#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>N>>M;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    int res=0;
    for(int i=0; i<N; ++i){
        if(binary_search(v.begin()+i+1, v.end(), M-v[i])){
            res++;
        }
    }
    cout << res << '\n';
}