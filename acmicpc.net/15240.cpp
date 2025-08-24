#include <bits/stdc++.h>
using namespace std;
vector<string> v;
char target;
char K; 
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int R, C;
void f(int y, int x){
    v[y][x]=K;
    for(int i=0; i<4; ++i){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny>=R || ny<0 || nx>=C || nx<0) continue;
        if(v[ny][nx]==target){
            f(ny, nx);
        }
    }
}
int main(){
    cin>>R>>C;
    for(int i=0; i<R; ++i){
        string str; cin>>str;
        v.push_back(str);
    }
    int Y, X;cin>>Y>>X>>K;
    if(K!=v[Y][X]) {
        target=v[Y][X];
        f(Y, X);
    }
    for(int i=0; i<R; ++i){
        cout << v[i] << '\n';
    }
}