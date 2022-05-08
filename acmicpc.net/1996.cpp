#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        for(int j=0; j<N; ++j){
            if(str[j]!='.'){
                arr[i][j]=99999;
                for(int k=0; k<8; ++k){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx>=0 && nx<N && ny>=0 && ny<N){
                        arr[nx][ny]+=str[j]-'0';
                    }
                }
            }
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(arr[i][j]>=99999) cout << "*";
            else if(arr[i][j]>=10) cout << "M";
            else cout << arr[i][j];
        }
        cout << '\n';
    }
}