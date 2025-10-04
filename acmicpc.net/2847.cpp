#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    vector<int> v;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        v.push_back(a);
    }
    int r=0;
    for(int i=N-2; i>=0; --i){
        while(v[i]>=v[i+1]){
            v[i]-=1;
            r+=1;
        }
    }
    cout <<r << '\n';
}