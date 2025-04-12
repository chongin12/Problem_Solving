#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii=pair<int,int>;
int arr[51][51];
int visited[51][51];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int INF = 987654321;
int res=INF;
struct Node {
    int x, y, t;
};
int N, M;
int f(vector<pii> k){
    int A[51][51];
    memset(visited, 0, sizeof visited);
    queue<Node> q;
    int cnt=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            A[i][j]=arr[i][j];
            if(A[i][j]==0) cnt++;
        }
    }

    if(cnt==0) return 0;

    for(auto it:k){
        visited[it.x][it.y]=1;
        q.push({it.x, it.y, 0});
    }

    int ret=0;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        ret=max(ret,cur.t);
        if(A[cur.x][cur.y]==0) {
            --cnt;
            if(cnt==0) return ret;
        }
        for(int i=0; i<4; ++i){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<N && !visited[nx][ny] && A[nx][ny]!=1){
                visited[nx][ny]=cur.t+1;
                
                q.push({nx,ny,cur.t+1});
            }
        }
    }

    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<N; ++j){
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    if(cnt!=0) return INF;

    return ret;
}
int main(){
    cin>>N>>M;
    vector<pii> v;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>arr[i][j];
            if(arr[i][j]==2) v.push_back({i,j});
        }
    }
    vector<int> temp(v.size());
    for(int i=0; i<M; ++i) temp[i]=1;

    do {
        vector<pii> k;
        // cout << '\n';
        for(int i=0; i<v.size(); ++i){
            if(temp[i]) {
                // cout << i << ", ";
                k.push_back(v[i]);
            }
        }
        // cout << '\n';
        res=min(res,f(k));

    } while(prev_permutation(temp.begin(), temp.end()));

    if(res==INF) cout << "-1\n";
    else cout << res << '\n';

}