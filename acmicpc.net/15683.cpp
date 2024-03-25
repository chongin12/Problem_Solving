#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int N, M;
vector<pii> v;
int dxdy[][2]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
int dir[10];
int arr[10][10];
void fillDirection(int d, int x, int y, int (&temp)[10][10]) {
    d=d%4;
    while(x>=0 && x<N && y>=0 && y<M && temp[x][y]!=6){
        if(temp[x][y]==0) temp[x][y]=7;
        x+=dxdy[d][0];
        y+=dxdy[d][1];
    }
}
int res=987654321;
void ff(int phase){
    if(phase==v.size()){
        int temp[10][10]={0,};
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                temp[i][j]=arr[i][j];
            }
        }
        for(int i=0; i<phase; ++i){
            auto cur=v[i];
            if(arr[cur.first][cur.second]==1){
                fillDirection(dir[i], cur.first, cur.second, temp);
            }
            else if(arr[cur.first][cur.second]==2){
                fillDirection(dir[i], cur.first, cur.second, temp);
                fillDirection(dir[i]+2, cur.first, cur.second, temp);
            }
            else if(arr[cur.first][cur.second]==3){
                fillDirection(dir[i], cur.first, cur.second, temp);
                fillDirection(dir[i]+1, cur.first, cur.second, temp);
            }
            else if(arr[cur.first][cur.second]==4){
                fillDirection(dir[i], cur.first, cur.second, temp);
                fillDirection(dir[i]+1, cur.first, cur.second, temp);
                fillDirection(dir[i]+2, cur.first, cur.second, temp);
            }
            else if(arr[cur.first][cur.second]==5){
                fillDirection(dir[i], cur.first, cur.second, temp);
                fillDirection(dir[i]+1, cur.first, cur.second, temp);
                fillDirection(dir[i]+2, cur.first, cur.second, temp);
                fillDirection(dir[i]+3, cur.first, cur.second, temp);
            }
        }
        int cnt=0;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(temp[i][j]==0) {
                    cnt++;
                }
            }
        }
        res=min(res,cnt);
        return;
    }
    for(int i=0; i<4; ++i){
        dir[phase]=i;
        ff(phase+1);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
            if(arr[i][j]>=1 && arr[i][j]<=5){
                v.push_back({i,j});
            }
        }
    }
    ff(0);
    cout << res << '\n';
}