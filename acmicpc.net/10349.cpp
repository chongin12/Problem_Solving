#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void init() {
    memset(arr, 0, sizeof arr);
}
struct Node {
    int x, y, w;
};
int main(){
    while(1){
        init();
        queue<Node> q;
        int res=0;
        int X; cin>>X; if(X==-1) break;
        int Y, T, L, W; cin>>Y>>T>>L>>W;
        for(int i=0; i<L; ++i){
            int x, y; cin>>x>>y;
            arr[x][y]=1;
            res++;
            q.push({x,y,1});
        }
        for(int i=0; i<W; ++i){
            int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
            if(x1==x2){
                if(y1>y2) swap(y1, y2);
                for(int y=y1; y<=y2; ++y){
                    arr[x1][y]=-1;
                }
            }
            else if(y1==y2){
                if(x1>x2) swap(x1, x2);
                for(int x=x1; x<=x2; ++x){
                    arr[x][y1]=-1;
                }
            }
            else {
                if(x1>x2){
                    swap(x1, x2);
                    swap(y1, y2);
                }
                for(int x=x1; x<=x2; ++x){
                    arr[x][y1]=-1;
                    if(y1>y2) y1--;
                    else y1++;
                }
            }
        }
        // cout << '\n';
        // for(int i=1; i<=X; ++i){
        //     for(int j=1; j<=Y; ++j){
        //         if(arr[i][j]==-1) cout << "X ";
        //         else cout << arr[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            if(cur.w>=T) break;
            for(int i=0; i<4; ++i){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if(nx>=1 && nx<=X && ny>=1 && ny<=Y && arr[nx][ny]==0){
                    q.push({nx, ny, cur.w+1});
                    arr[nx][ny]=1;
                    res++;
                }
            }
        }
        cout << res << '\n';
    }
}