#include <bits/stdc++.h>
using namespace std;
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};
int main(){
    int R, S; cin>>R>>S;
    vector<string> v;
    for(int i=0; i<R; ++i){
        string str; cin>>str;
        v.push_back(str);
    }
    int res=0;
    int candidate=0;
    for(int i=0; i<R; ++i){
        for(int j=0; j<S; ++j){
            int cnt=0;
            for(int k=0; k<8; ++k){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=0 && nx<R && ny>=0 && ny<S && v[nx][ny]=='o'){
                    cnt++;
                }
            }
            if(v[i][j]=='o') res+=cnt;
            else candidate=max(candidate,cnt);
        }
    }
    cout << res/2+candidate << '\n';
}