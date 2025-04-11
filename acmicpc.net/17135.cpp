#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
struct Node {
    int x, y, depth;
};
int arr[16][16];
int temp[16][16];
int N, M, D;
int dx[]={0,-1,0};
int dy[]={-1,0,1};
int visited[16][16];
int cnt=0;
int res=0;
void init(){
    memset(visited, 0, sizeof visited);
}
pii bfs(int x, int y) {
    queue<Node> q;
    q.push({x,y,1});
    visited[x][y]=1;
    if(temp[x][y]) return {x,y};
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        // cout << "cur = " << cur.x << ", " << cur.y << '\n';
        for(int i=0; i<3; ++i){
            int nx = cur.x+dx[i];
            int ny = cur.y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && !visited[nx][ny] && cur.depth<D){
                if(temp[nx][ny]){
                    return {nx,ny};
                }
                visited[nx][ny]=1;
                q.push({nx,ny,cur.depth+1});
            }
        }
    }
    // cout << "bfs("<<x<<","<<y<<")="<<ret.first<<","<<ret.second<<'\n';
    return {-1,-1};
}
void f(int a, int b, int c){
    cnt=0;
    // cout << "\n\na : " << a << ", b : " << b << ", c : " << c << '\n';
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            temp[i][j]=arr[i][j];
        }
    }

    for(int i=0; i<N; ++i){
        // cout << '\n';
        // for(int w1=0; w1<N; ++w1){
        //     for(int w2=0; w2<M; ++w2){
        //         cout << temp[w1][w2] << " ";
        //     }
        //     cout << '\n';
        // }
        set<pii> v;
        init();
        auto f1=bfs(N-1, a);
        if(f1.first!=-1) v.insert(f1);
        init();
        auto f2=bfs(N-1, b);
        if(f2.first!=-1) v.insert(f2);
        init();
        auto f3=bfs(N-1, c);
        if(f3.first!=-1) v.insert(f3);

        for(auto it:v){
            temp[it.first][it.second]=0;
            cnt++;
        }

        for(int i=N-1; i>0; --i){
            for(int j=0; j<M; ++j){
                temp[i][j]=temp[i-1][j];
            }
        }
        for(int j=0; j<M; ++j){
            temp[0][j]=0;
        }
    }
    // cout << "cnt = " << cnt << '\n';
}
int main(){
    cin>>N>>M>>D;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<M; ++i){
        for(int j=i+1; j<M; ++j){
            for(int k=j+1; k<M; ++k){
                cnt=0;
                f(i,j,k);
                res=max(res,cnt);
            }
        }
    }

    cout << res << '\n';
}