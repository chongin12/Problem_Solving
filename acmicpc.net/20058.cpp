#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int arr[100][100];
int N, Q;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int maxCnt=0;
int visited[100][100];
int temp[100][100]={0,};
int szN=1<<N;
int dfs(int x, int y, int sz){
    int ret=1;
    visited[x][y]=1;
    for(int i=0; i<4; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<sz && ny>=0 && ny<sz && !visited[nx][ny] && arr[nx][ny]!=0) ret+=dfs(nx,ny,sz);
    }
    return ret;
}
int bfs(int x, int y, int sz){
    int ret=1;

    queue<pii> q;
    q.push({x,y});
    visited[x][y]=1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; ++i){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=0 && nx<sz && ny>=0 && ny<sz && !visited[nx][ny] && arr[nx][ny]!=0) {
                q.push({nx,ny});
                visited[nx][ny]=1;
                ret++;
            }
        }
    }
    return ret;
}
void rotate(int r, int c, int sz){ // (r,c)에서 sz만큼 격자를 90도 회전
    // cout << "rotate : " << r <<", "<<c << "\n";
    memset(temp, 0, sizeof temp);
    for(int i=0; i<sz; ++i){
        for(int j=0; j<sz; ++j){
            temp[i][j]=arr[r+i][c+j];
        }
    }
    for(int i=0; i<sz; ++i){
        for(int j=0; j<sz; ++j){
            arr[r+j][c+sz-i-1] = temp[i][j];
        }
    }
}
void f(int l){ // 크기가 2^l인 사각형들로 쪼개기
    int sz=1<<l;
    int szz=szN/sz;
    for(int i=0; i<szz; ++i){
        for(int j=0; j<szz; ++j){
            rotate(i*sz, j*sz, sz);
        }
    }
}
void melt(){
    int sz=szN;
    memset(temp, 0, sizeof temp);
    for(int i=0; i<sz; ++i){
        for(int j=0; j<sz; ++j){
            int cnt=0;
            for(int w=0; w<4; ++w){
                int nx=i+dx[w];
                int ny=j+dy[w];
                if(nx>=0 && nx<sz && ny>=0 && ny<sz && arr[nx][ny]!=0) cnt++;
            }
            if(cnt<3) temp[i][j]=1;
            else temp[i][j]=0;
        }
    }
    for(int i=0; i<sz; ++i){
        for(int j=0; j<sz; ++j){
            if(temp[i][j]) arr[i][j]=max(0,arr[i][j]-1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>Q;
    szN=1<<N;
    int sz=szN;
    memset(visited, 0, sizeof visited);
    for(int i=0; i<sz; ++i){
        for(int j=0; j<sz; ++j){
            cin>>arr[i][j];
        }
    }
    while(Q--){
        int q; cin>>q;
        f(q);
        melt();
        // for(int i=0; i<(1<<N); ++i){
        //     for(int j=0; j<(1<<N); ++j){
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
    }
    int res=0;
    for(int i=0; i<sz; ++i){
        for(int j=0; j<sz; ++j){
            res+=arr[i][j];
            if(!visited[i][j] && arr[i][j]>0) maxCnt = max(maxCnt, bfs(i,j,sz));
        }
    }
    cout << res << '\n' << maxCnt << '\n';
}

/*
(0,0) -> (0,sz-1)
(0,1) -> (1,sz-1)
(0,2) -> (2,sz-1)

...

(1,0) -> (0,sz-2)

...

(sz-1,sz-1) -> (sz-1,0)
*/