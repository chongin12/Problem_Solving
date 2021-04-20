#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;
int N, M;
int arr[20][20];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int SharkX, SharkY, SharkSize=2, eaten=0, Stime=0;
struct node {
    int x, y, depth;
    node(int x, int y, int depth) : x(x), y(y), depth(depth) {}
};
struct fish {
    int x, y, size;
    fish(int x, int y, int size) : x(x), y(y), size(size) {}
};
int bfs(int Sx, int Sy, int Tx, int Ty) {
    queue<node> q;
    int visit[20][20] = {0, };
    visit[Sy][Sx] = 1;
    q.push(node(Sx, Sy, 0));
    while(!q.empty()){
        node cur = q.front(); q.pop();
        if(cur.x == Tx && cur.y == Ty) return cur.depth;
        for(int k=0; k<4; ++k){
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];
            if(nx>=0 && nx<N && ny>=0 && ny<N && !visit[ny][nx] && arr[ny][nx] <= SharkSize) {
                visit[ny][nx] = 1;
                q.push(node(nx, ny, cur.depth+1));
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                SharkX = j, SharkY = i;
            }
        }
    }
    //1. search next fish : start from top left, brute-force
    //while 1. decide the fish is eatable
    //2. move, eat, (sizeup)

    while(1){
        int nearestDist=INF;
        fish nearestFish = fish(0,0,0);
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(arr[i][j] == 9 || arr[i][j] == 0) continue;
                if(arr[i][j] < SharkSize){
                    //bfs
                    int dist = bfs(SharkX, SharkY, j, i);
                    if(dist == -1) continue;
                    if(dist < nearestDist){
                        nearestDist = dist;
                        nearestFish = fish(j, i, arr[i][j]);
                    }
                }
            }
        }
        if(nearestDist == INF) {
            cout << Stime << '\n';
            return 0;
        }
        Stime += nearestDist;
        arr[SharkY][SharkX] = 0;
        arr[nearestFish.y][nearestFish.x] = 9;
        SharkX = nearestFish.x;
        SharkY = nearestFish.y;
        ++eaten;
        if(eaten == SharkSize) ++SharkSize,eaten=0;
    }
}