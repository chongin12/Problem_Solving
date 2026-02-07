#include <bits/stdc++.h>
using namespace std;
map<int, int> x, y;
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a, b; cin>>a>>b;
        x[a]++;
        y[b]++;
    }
    int res=0;
    for(auto it:x){
        int d=it.second;
        if(d==1) continue;
        res+=1;
    }
    for(auto it:y){
        int d=it.second;
        if(d==1) continue;
        res+=1;
    }
    cout << res << '\n';
}