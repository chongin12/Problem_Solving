#include <iostream>
#include <queue>
#include <string>
using namespace std;
string arr[1012];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
struct node {
    int x, y, count, breakable;
    node(int x, int y, int count, int breakable) : x(x), y(y), count(count), breakable(breakable) {}
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }
    int visit[1000][1000];
    queue<node> q;
    visit[0][0] = 1;
    q.push(node(0, 0, 1, 1));
    while(!q.empty()){
        node pnode = q.front(); q.pop();
        int pi=pnode.x, pj=pnode.y, pc=pnode.count, pb=pnode.breakable;
        if(pi==N-1 && pj==M-1){
            cout << pc << '\n';
            return 0;
        }
        for(int i=0; i<4; ++i){
            int mi = pi+dx[i], mj = pj+dy[i];
            if(mi>=0 && mi<N && mj>=0 && mj<M && visit[mi][mj]!=1) {
                if(pb==1 && visit[mi][mj]==0) {
                    if(arr[mi][mj]=='0'){
                        visit[mi][mj]=1;
                        q.push(node(mi, mj, pc+1, pb));
                    }
                    else {
                        visit[mi][mj]=2;
                        q.push(node(mi, mj, pc+1, 0));
                    }
                }
                else if(pb==1 && visit[mi][mj]==2) {
                    if(arr[mi][mj]=='0'){
                        visit[mi][mj]=1;
                        q.push(node(mi, mj, pc+1, pb));
                    }
                    else {
                        visit[mi][mj]=2;
                        q.push(node(mi, mj, pc+1, 0));
                    }
                }
                else if(pb==0 && visit[mi][mj]==0) {
                    if(arr[mi][mj]=='0'){
                        visit[mi][mj]=2;
                        q.push(node(mi, mj, pc+1, pb));
                    }
                }
            }
        }
    }
    cout << "-1" << '\n';
}