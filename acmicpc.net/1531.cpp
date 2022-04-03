#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int main(){
    int N, M; cin>>N>>M;
    for(int i=0; i<N; ++i){
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        for(int x=x1; x<=x2; ++x){
            for(int y=y1; y<=y2; ++y){
                arr[x][y]++;
            }
        }
    }
    int res=0;
    for(int i=0; i<101; ++i){
        for(int j=0; j<101; ++j){
            if(arr[i][j]>M) res++;
        }
    }
    cout << res << '\n';
}