#include <bits/stdc++.h>
using namespace std;
int arr1[201][201], arr2[201][201];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int INF = 987654321;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin>>N>>K;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>arr1[i][j];
            if(arr1[i][j]==0) arr1[i][j]=INF;
            arr2[i][j]=arr1[i][j];
        }
    }
    int S, X, Y; cin>>S>>X>>Y;
    for(int s=0; s<S; ++s){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                int ret=arr1[i][j];
                if(ret!=INF) continue;
                ret=arr2[i][j];
                for(int k=0; k<4; ++k){
                    int nx=i+dx[k], ny=j+dy[k];
                    if(nx>=0 && nx<N && ny>=0 && ny<N){
                        ret=min(ret, arr1[nx][ny]);
                    }
                }
                arr2[i][j]=ret;
            }
        }
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                arr1[i][j]=arr2[i][j];
                // cout << arr1[i][j] << " ";
            }
            // cout << '\n';
        }
        // cout << '\n';
    }
    if(arr1[X-1][Y-1]==INF) cout << "0\n";
    else cout << arr1[X-1][Y-1] << '\n';
}