#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int N, M, K;
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};
map<string,int> m;
void dfs(string s, int phase, int x, int y){
    m[s]++;
    if(phase==4) return;
    for(int i=0; i<8; ++i){
        int nx = (x+dx[i]+N)%N;
        int ny = (y+dy[i]+M)%M;
        dfs(s+v[nx][ny], phase+1, nx, ny);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M>>K;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        v.push_back(str);
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            string str = "";
            str+=v[i][j];
            dfs(str, 0, i, j);
        }
    }
    for(int i=0; i<K; ++i){
        string str; cin>>str;
        cout << m[str] << '\n';
    }
}
/*
10 10 2
aaaaaaaaaaa
aaaaaaaaaaa
aaaaaaaaaaa
aaaaaaaaaaa
aaaaaaaaaaa
aaaaaaaaaaa
aaaaaaaaaaa
aaaaaaaaaaa
aaaaaaaaaaa
aaaaaaaaaaa
aaaaa
*/