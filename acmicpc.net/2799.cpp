#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int res[6];
int main(){
    int M, N; cin>>M>>N;
    for(int i=0; i<5*M+1; ++i){
        string a; cin>>a;
        v.push_back(a);
    }
    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            int cnt=0;
            for(int k=0; k<4; ++k){
                if(v[i*5+1+k][j*5+1]=='*') cnt++;
            }
            res[cnt]++;
        }
    }
    for(int i=0; i<5; ++i){
        cout << res[i] << ' ';
    }
    cout << '\n';
}