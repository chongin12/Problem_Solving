#include <bits/stdc++.h>
using namespace std;
int arr1[31][31];
int arr2[31][31];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int N, M;
void f(int i, int j, int from, int to){
    arr1[i][j]=to;
    for(int k=0; k<4; ++k){
        int ni=i+dx[k];
        int nj=j+dy[k];
        if(ni>=0 && ni<N && nj>=0 && nj<M && arr1[ni][nj]==from && arr1[ni][nj]!=to){
            f(ni,nj,from,to);
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr1[i][j];
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr2[i][j];
        }
    }
    bool flag=false;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(flag) break;
            if(arr1[i][j]!=arr2[i][j]){
                flag=true;
                f(i,j,arr1[i][j], arr2[i][j]);
            }
        }
    }
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<M; ++j){
    //         cout << arr1[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    bool res=true;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(arr1[i][j]!=arr2[i][j]){
                res=false;
            }
        }
    }
    if(res) cout << "YES\n";
    else cout << "NO\n";
}