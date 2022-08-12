#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M; cin>>N>>M;
    vector<int> v1,v2;
    v1.push_back(0);
    v1.push_back(N);
    v2.push_back(0);
    v2.push_back(M);
    int q; cin>>q;
    while(q--){
        int a,b; cin>>a>>b;
        if(a==1) v1.push_back(b);
        else v2.push_back(b);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int v1Max=0;
    for(int i=1; i<v1.size(); ++i){
        v1Max=max(v1Max,v1[i]-v1[i-1]);
    }
    int v2Max=0;
    for(int i=1; i<v2.size(); ++i){
        v2Max=max(v2Max,v2[i]-v2[i-1]);
    }
    cout << v1Max*v2Max << '\n';
}