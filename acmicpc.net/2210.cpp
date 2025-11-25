#include <bits/stdc++.h>
using namespace std;
string arr[5][5];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

set<string> res;
void f(int i, int j, string s){
    if(s.size()==5){
        res.insert(s+arr[i][j]);
        return;
    }
    for(int k=0; k<4; ++k){
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(nx>=0 && nx<5 && ny>=0 && ny<5){
            f(nx, ny, s+arr[i][j]);
        }
    }
}
int main(){
    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            f(i, j, "");
        }
    }
    cout << res.size() << '\n';
}