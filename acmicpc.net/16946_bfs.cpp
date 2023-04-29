#include <bits/stdc++.h>
using namespace std;
vector<string> input;
int arr[1001][1001];
int num[1001][1001]; // 영역 번호
int cnt[1000001]; // 해당 영역에 속한 개수
int visited[1001][1001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int res[1001][1001];
int N, M;
int now=0;
void bfs(int i, int j){
    ++now;
    queue<pair<int,int> > q;
    q.push({i,j});
    visited[i][j]=1;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        num[cur.first][cur.second] = now;
        ++cnt[now];
        for(int w=0; w<4; ++w){
            int nx=cur.first+dx[w];
            int ny=cur.second+dy[w];
            if(nx>=0 && nx<N && ny>=0 && ny<M && !visited[nx][ny] && arr[nx][ny]==0){
                visited[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
    // cout << "i : " << i << ", j : " << j << '\n';
    // cout << "cnt["<<now<<"]="<<cnt[now]<<'\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        string str;cin>>str;
        input.push_back(str);
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            arr[i][j]=input[i][j]-'0';
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(visited[i][j]) continue;
            if(arr[i][j]==0) bfs(i, j);
        }
    }
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<M; ++j){
    //         cout << num[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(arr[i][j]==1) {
                int tmp = 1;
                vector<int> grps;
                for(int k=0; k<4; ++k){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx>=0 && nx<N && ny>=0 && ny<M && arr[nx][ny]==0 && num[nx][ny]!=0){
                        bool flag=true;
                        for(auto it:grps){
                            if(it==num[nx][ny]) flag=false;
                        }
                        if(flag) {
                            tmp+=cnt[num[nx][ny]];
                            grps.push_back(num[nx][ny]);
                        }
                    }
                }
                tmp%=10;
                res[i][j]=tmp;
                // cout << "arr["<<i<<"]["<<j<<"]="<<arr[i][j] << '\n';
            }
            else{
                res[i][j]=0;
            }
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cout << res[i][j];
        }
        cout << '\n';
    }
}