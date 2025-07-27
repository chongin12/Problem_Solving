#include <bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int arr[101][101];
int chk[101][101];
int main(){
    int N, M, R; cin>>N>>M>>R;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            cin>>arr[i][j];
        }
    }
    int res=0;
    while(R--){
        int X, Y; char ch;
        cin>>X>>Y>>ch;
        int D;
        if(ch=='E'){
            D=0;
        } else if(ch=='W'){
            D=2;
        } else if(ch=='S'){
            D=1;
        } else {
            D=3;
        }
        int temp=0;
        if(!chk[X][Y]) {
            chk[X][Y]=1;
            temp=arr[X][Y]-1;
            res++;
        }
        int cx=X+dx[D], cy=Y+dy[D];
        while(temp>0){
            if(cx<=0 || cx>N || cy<=0 ||cy>M) break;
            if(!chk[cx][cy]){
                chk[cx][cy]=1;
                temp=max(temp,arr[cx][cy]);
                res++;
            }
            temp--;
            cx+=dx[D];
            cy+=dy[D];
        }

        cin>>X>>Y;
        chk[X][Y]=0;
    }
    cout << res << '\n';
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            cout << (chk[i][j]?"F":"S") << ' ';
        }
        cout << '\n';
    }
}