#include <bits/stdc++.h>
using namespace std;
int arr[51][10];
int order[11];
int visited[11];
int N;
int res=0;
void f(int phase){
    // cout << "phase : " << phase << '\n';
    if(phase==4) {
        f(phase+1);
        return;
    }
    if(phase==10){
        // calc
        int nowOrder=1;
        int score=0;
        int inning=1;
        int outCount=0;
        int isOnLu[]={0,0,0,0}; // 1루, 2루, 3루
        while(inning <= N) {
            // cout << "inning : " << inning << '\n';
            // cout << "order["<<nowOrder<<"]="<<order[nowOrder]<<'\n';
            // cout << arr[inning][order[nowOrder]]<<'\n';
            switch (arr[inning][order[nowOrder]]) {
            case 0:
                outCount++;
                break;
            case 1:
                if(isOnLu[3]) score++,isOnLu[3]=0;
                if(isOnLu[2]) isOnLu[3]=isOnLu[2], isOnLu[2]=0;
                if(isOnLu[1]) isOnLu[2]=isOnLu[1], isOnLu[1]=0;
                isOnLu[1]=1;
                break;
            case 2:
                if(isOnLu[3]) score++,isOnLu[3]=0;
                if(isOnLu[2]) score++,isOnLu[2]=0;
                if(isOnLu[1]) isOnLu[3]=isOnLu[1], isOnLu[1]=0;
                isOnLu[2]=1;
                break;
            case 3:
                if(isOnLu[3]) score++,isOnLu[3]=0;
                if(isOnLu[2]) score++,isOnLu[2]=0;
                if(isOnLu[1]) score++,isOnLu[1]=0;
                isOnLu[3]=1;
                break;
            case 4:
                if(isOnLu[3]) score++,isOnLu[3]=0;
                if(isOnLu[2]) score++,isOnLu[2]=0;
                if(isOnLu[1]) score++,isOnLu[1]=0;
                score++;
                break;
            default:
                break;
            }
            nowOrder++;
            if(nowOrder>=10) nowOrder-=9;
            if(outCount==3){
                outCount=0;
                inning++;
                isOnLu[3]=0;
                isOnLu[2]=0;
                isOnLu[1]=0;
            }
        }
        res=max(res,score);
        return;
    }
    for(int i=2; i<=9; ++i){
        if(visited[i]) continue;
        visited[i]=1;
        order[phase]=i;
        f(phase+1);
        visited[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=9; ++j){
            cin>>arr[i][j];
        }
    }
    order[4]=1;
    visited[1]=1;
    f(1);
    cout << res << '\n';
}