#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int arr[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int N, M;
int MAX_ = -1;
bool safe(int x, int y) {
    if(x<0 || x>=N || y<0 || y>=M) return false;
    return true;
}
void dfs(int i, int j, int previ, int prevj, int si, int sj, int depth, int count){
    if(!safe(i,j)) return;
    if(depth!=1 && i==si && j==sj) return;
    if(depth == 4) {
        //cout << "depth 4 : " << i << " " << j << " " << previ << " " << prevj << " " << depth << " " << count+arr[i][j] << '\n';
        MAX_ = max(MAX_, count+arr[i][j]);
        return;
    }
    else{
        for(int k=0; k<4; ++k){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(!safe(nx, ny)) continue;
            if(nx==previ && ny == prevj) continue;
            dfs(nx, ny, i, j, si, sj, depth+1, count+arr[i][j]);
        }
    }
    if(depth == 3) {
        if(previ==i && prevj<j) { // right
            dfs(i-1, j-1, i, j, si, sj, 4, count+arr[i][j]);
            dfs(i+1, j-1, i, j, si, sj, 4, count+arr[i][j]);
        }
        else if(previ==i && prevj>j) { // left
            dfs(i-1, j+1, i, j, si, sj, 4, count+arr[i][j]);
            dfs(i+1, j+1, i, j, si, sj, 4, count+arr[i][j]);
        }
        else if(prevj==j && previ<i) { // down
            dfs(i-1, j-1, i, j, si, sj, 4, count+arr[i][j]);
            dfs(i-1, j+1, i, j, si, sj, 4, count+arr[i][j]);
        }
        else if(prevj==j && previ>i) { // up
            dfs(i+1, j-1, i, j, si, sj, 4, count+arr[i][j]);
            dfs(i+1, j+1, i, j, si, sj, 4, count+arr[i][j]);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            dfs(i, j, -1, -1, i, j, 1, 0);
        }
    }
    cout << MAX_ << '\n';
}