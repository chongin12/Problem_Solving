#include <bits/stdc++.h>
using namespace std;
int arr[5][5];
int visited[5][5];
void chk(int a){
    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            if(arr[i][j]==a) visited[i][j]=1;
        }
    }
}
int bingo(){
    int ret=0;
    for(int i=0; i<5; ++i){
        bool flag=true;
        for(int j=0; j<5; ++j){
            if(!visited[i][j]) flag=false;
        }
        if(flag) ret++;
    }
    for(int i=0; i<5; ++i){
        bool flag=true;
        for(int j=0; j<5; ++j){
            if(!visited[j][i]) flag=false;
        }
        if(flag) ret++;
    }
    bool flag=true;
    for(int j=0; j<5; ++j){
        if(!visited[j][j]) flag=false;
    }
    if(flag) ret++;
    flag=true;
    for(int j=0; j<5; ++j){
        if(!visited[j][4-j]) flag=false;
    }
    if(flag) ret++;
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            int a; cin>>a;
            chk(a);
            if(bingo()>=3) {
                cout << i*5+j+1 << '\n';
                return 0;
            }
        }
    }
}