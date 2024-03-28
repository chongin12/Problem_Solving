#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using piii=pair<pair<int,int>,int>;
vector<string> arr;
int R,C;
int id[51][51];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int match[301];
vector<pii> Cpos, Ppos;
vector<pii> G[301];
const int SHIFT = 101;
int visited[51][51];
int bip_visited[301];
void init(){
    for(int i=0; i<51; ++i)
        for(int j=0; j<51; ++j)
            visited[i][j]=0;
}
void bip_init(){
    for(int i=0; i<301; ++i) bip_visited[i]=0;
}
void bfs(int x, int y){
    init();
    queue<piii> q;
    q.push({{x,y},0});
    visited[x][y]=1;
    while(!q.empty()){
        piii cur = q.front(); q.pop();
        int cx=cur.first.first, cy=cur.first.second, clev=cur.second;
        if(arr[cx][cy]=='P'){
            G[id[x][y]].push_back({id[cx][cy],clev});
        }
        for(int i=0; i<4; ++i){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>=0 && nx<R && ny>=0 && ny<C && arr[nx][ny]!='X' && !visited[nx][ny]){
                q.push({{nx,ny},clev+1});
                visited[nx][ny]=1;
            }
        }
    }
}
bool bip_dfs(int c, int k){
    if(bip_visited[c]) return false;
    bip_visited[c]=1;
    for(auto it:G[c]){
        if(it.second>k) break;
        if(match[it.first]==-1){
            match[it.first] = c;
            bip_visited[it.first]=1;
            return true;
        }
    }
    for(auto it:G[c]){
        if(it.second>k) break;
        if(bip_dfs(match[it.first], k)){
            match[it.first] = c;
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>R>>C;
    int N=0, M=0;
    for(int i=0; i<R; ++i){
        string str; cin>>str;
        arr.push_back(str);
        for(int j=0; j<C; ++j){
            if(arr[i][j]=='C'){
                id[i][j]=N;
                N+=1;
                Cpos.push_back({i,j});
            }
            else if(arr[i][j]=='P'){
                id[i][j]=M + SHIFT;
                M+=1;
                Ppos.push_back({i,j});
            }
        }
    }
    for(auto it:Cpos){
        bfs(it.first, it.second);
    }
    
    for(int i=0; i<N; ++i){
        int px = Cpos[i].first, py=Cpos[i].second;
        sort(G[i].begin(), G[i].end(), [](pii a, pii b){
            return a.second < b.second;
        });
    }
    if(N==0){
        cout << "0\n";
        return 0;
    }
    for(int k=1500; k>=0; --k){
        int cnt=0;
        for(int i=0; i<301; ++i) match[i]=-1;
        for(int i=0; i<N; ++i){
            bip_init();
            if(bip_dfs(i, k)) cnt++;
        }
        if(cnt!=N){
            if(k==1500) break;
            cout << k+1 << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}