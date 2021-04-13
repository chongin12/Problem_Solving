#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> v;
int visit[101][101], N;
int dx[4] = {0, -1, 0, +1};
int dy[4] = {-1, 0, +1, 0};
void dfs(int i, int j){
    visit[i][j]=1;
    for(int k=0; k<4; ++k){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0 && x<N && y>=0 && y<N && !visit[x][y]){
            if(v[i][j] == v[x][y]) dfs(x,y);
        }
    }
}
int main(){
    cin >> N;
    for(int i=0; i<N; ++i){
        string str; cin >> str;
        v.push_back(str);
    }
    int result1=0, result2=0;
    for(int i=0; i<N; ++i){ // case 1
        for(int j=0; j<N; ++j){
            if(!visit[i][j]){
                dfs(i, j);
                result1++;
            }
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            visit[i][j]=0;
            if(v[i][j] == 'G') v[i][j] = 'R';
        }
    }
    for(int i=0; i<N; ++i){ // case 2
        for(int j=0; j<N; ++j){
            if(!visit[i][j]){
                dfs(i, j);
                result2++;
            }
        }
    }
    cout << result1 << " " << result2 << '\n';
}