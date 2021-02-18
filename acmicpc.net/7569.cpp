#include <iostream>
#include <queue>
using namespace std;
int arr[101][101][101];
int visit[101][101][101];
int MAX = -1;
struct point {
    int h, n, m, val;
    point(int h, int n, int m, int val) {
        this->h = h;
        this->n = n;
        this->m = m;
        this->val = val;
    }
};
queue<point> q;
int H, N, M; 
bool safe(int i, int j, int k){
    if(i<0 || i>=H || j<0 || j>=N || k<0 || k>=M) return false;
    else return true;
}
bool moveable(int i, int j, int k, int val){
    if(arr[i][j][k] == 0 && !visit[i][j][k]) return true;
    else return false;
}
void f(){
    while(!q.empty()){
        point p = q.front();
        q.pop();
        int i=p.h, j=p.n, k=p.m, val=p.val;
        arr[i][j][k] = p.val;
        if(safe(i-1, j, k) && moveable(i-1, j, k, val+1)) {
            q.push({i-1, j, k, val+1});
            visit[i-1][j][k]=1;
        }
        if(safe(i+1, j, k) && moveable(i+1, j, k, val+1)) {
            q.push({i+1, j, k, val+1});
            visit[i+1][j][k]=1;
        }
        if(safe(i, j-1, k) && moveable(i, j-1, k, val+1)) {
            q.push({i, j-1, k, val+1});
            visit[i][j-1][k]=1;
        }
        if(safe(i, j+1, k) && moveable(i, j+1, k, val+1)) {
            q.push({i, j+1, k, val+1});
            visit[i][j+1][k]=1;
        }
        if(safe(i, j, k-1) && moveable(i, j, k-1, val+1)) {
            q.push({i, j, k-1, val+1});
            visit[i][j][k-1]=1;
        }
        if(safe(i, j, k+1) && moveable(i, j, k+1, val+1)) {
            q.push({i, j, k+1, val+1});
            visit[i][j][k+1]=1;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N >> H;
    for(int i=0; i<H; ++i){
        for(int j=0; j<N; ++j){
            for(int k=0; k<M; ++k){
                cin >> arr[i][j][k];
            }
        }
    }
    for(int i=0; i<H; ++i){
        for(int j=0; j<N; ++j){
            for(int k=0; k<M; ++k){
                if(arr[i][j][k]==1){
                    q.push({i, j, k, 1});
                    visit[i][j][k] = 1;
                }
            }
        }
    }
    f();
    int max=-1;
    for(int i=0; i<H; ++i){
        for(int j=0; j<N; ++j){
            for(int k=0; k<M; ++k){
                if(arr[i][j][k] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                if(arr[i][j][k]>max){
                    max=arr[i][j][k];
                }
            }
        }
    }
    cout << max-1 << '\n';
}