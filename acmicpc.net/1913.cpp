#include <bits/stdc++.h>
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int arr[1000][1000];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin>>N;
    int target; cin>>target;
    int curx=N/2, cury=N/2;
    int dir=0;
    int phase=1;
    int nxtphase=3;
    int cnt=1;

    int rx, ry;
    while(cnt<=N*N){
        // cout << "curx="<<curx<<", cury="<<cury << ", cnt="<<cnt<<", dir="<<dir<<'\n';
        arr[curx][cury]=cnt;
        if(cnt==target){
            rx=curx, ry=cury;
        }
        cnt++;
        curx+=dx[dir];
        cury+=dy[dir];
        phase--;
        if(phase==0){
            phase=nxtphase/2;
            nxtphase++;
            dir=(dir+1)%4;
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    cout << rx+1 << " " << ry+1 << '\n';
}