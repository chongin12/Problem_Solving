#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<int> v;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    int M; cin>>M;
    for(int i=0; i<M; ++i){
        int a; cin>>a;
        if(binary_search(v.begin(), v.end(), a)) cout << "1 ";
        else cout << "0 ";
    }
    cout << '\n';
}