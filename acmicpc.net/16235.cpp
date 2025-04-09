#include <bits/stdc++.h>
using namespace std;
int arr[12][12];
int A[12][12], oriA[12][12];
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,-1,-1,-1,0,1,1,1};
deque<int> dq[12][12];
struct Node {
    int x, y, z;
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, K; cin>>N>>M>>K;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            cin>>oriA[i][j];
            A[i][j]=5;
        }
    }
    for(int i=0; i<M; ++i){
        int x, y, z; cin>>x>>y>>z;
        dq[x][y].push_back(z);
    }
    while(K--){
        vector<Node> dead, toGrow;
        for(int i=1; i<=N; ++i){
            for(int j=1; j<=N; ++j){
                int size=dq[i][j].size();
                for(int k=0; k<size; ++k){
                    auto cur = dq[i][j].front(); dq[i][j].pop_front();
                    if(A[i][j]>=cur) {
                        dq[i][j].push_back(cur+1);
                        A[i][j]-=cur;
                        if((cur+1)%5==0) toGrow.push_back({i,j,0});
                    }
                    else dead.push_back({i,j,cur});
                }
            }
        }

        for(auto it:dead) {
            A[it.x][it.y]+=it.z/2;
        }

        
        for(auto it:toGrow){
            for(int w=0; w<8; ++w){
                int nx=it.x+dx[w];
                int ny=it.y+dy[w];
                if(nx>=1 && nx<=N && ny>=1 && ny<=N){
                    dq[nx][ny].push_front(1);
                }
            }
        } 

        for(int i=1; i<=N; ++i){
            for(int j=1; j<=N; ++j){
                A[i][j]+=oriA[i][j];
            }
        }
    }

    int cnt=0;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            cnt+=dq[i][j].size();
        }
    }
    cout << cnt << '\n';
}