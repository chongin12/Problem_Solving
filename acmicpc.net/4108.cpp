#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        vector<string> v(101);
        int R,C; cin>>R>>C;
        if(R==0 && C==0) break;
        for(int i=0; i<R; ++i){
            cin>>v[i];
        }
        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                if(v[i][j]=='*'){
                    arr[i][j]=-1;
                    continue;
                }
                int cnt=0;
                for(int k=0; k<8; ++k){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx>=0 && nx<R && ny>=0 && ny<C && v[nx][ny]=='*'){
                        cnt++;
                    }
                }
                arr[i][j]=cnt;
            }
        }
        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                if(arr[i][j]==-1) cout << "*";
                else cout << arr[i][j];
            }
            cout << '\n';
        }
    }
}