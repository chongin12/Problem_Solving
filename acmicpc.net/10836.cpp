#include <bits/stdc++.h>
using namespace std;
int arr[801][801];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int M, N; cin>>M>>N;
    vector<int> res;
    for(int i=0; i<M*2-1; ++i) res.push_back(1);
    for(int i=0; i<N; ++i){
        int a, b, c; cin>>a>>b>>c;
        int cnt=0;
        for(int j=0; j<a; ++j,++cnt) ;
        for(int j=0; j<b; ++j,++cnt) res[cnt]+=1;
        for(int j=0; j<c; ++j,++cnt) res[cnt]+=2;
    }
    int idx=res.size();
    for(int i=M-1; i>=0; --i){
        arr[0][i]=res[--idx];
    }
    for(int i=1; i<M; ++i){
        arr[i][0]=res[--idx];
    }
    for(int i=0; i<M; ++i){
        for(int j=0; j<M; ++j){
            if(i>0 && j>0) arr[i][j]=max({arr[i][j-1], arr[i-1][j], arr[i-1][j-1]});
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}