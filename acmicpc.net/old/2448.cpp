#include <bits/stdc++.h>
using namespace std;
bool arr[3100][6200];
void f(int startR, int startC, int r){
    if(r==3){
        arr[startR][startC+2]=1;
        arr[startR+1][startC+1]=1;
        arr[startR+1][startC+3]=1;
        for(int i=0; i<5; ++i){
            arr[startR+2][startC+i]=1;
        }
    }
    else{
        f(startR, startC+r/2, r/2);
        f(startR+r/2, startC, r/2);
        f(startR+r/2, startC+r, r/2);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin>>N;
    f(0,0,N);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N*2; ++j){
            if(arr[i][j]) cout << "*";
            else cout << " ";
        }
        cout << '\n';
    }
}