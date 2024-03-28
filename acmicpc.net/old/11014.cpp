#include <bits/stdc++.h>
using namespace std;
const int MN=10000;
int N;
vector<int> G[MN]; // G[u] : u와 연결된 정점 v의 리스트. 단, u는 L에, v는 R에 속함.
vector<int> R(MN); // R[v] : v와 연결된 정점 u의 리스트. 단, u는 L에, v는 R에 속하며, 없으면 -1.
vector<int> C(MN); // C[v] : 증가 경로를 찾을 때 v를 방문했으면 1
bool Augment(int v){ // u에서 시작하는 증가 경로가 있으면 true
    for(auto i:G[v]){
        if(C[i]) continue; C[i]=1;
        if(R[i]==-1 || Augment(R[i])){
            R[i]=v; return true;
        }
    }
    return false;
}
int Match(){
    int res=0;
    fill(R.begin(), R.end(), -1);
    for(int i=1; i<=N; ++i){
        fill(C.begin(), C.end(), 0);
        if(Augment(i)){
            res++;
            // cout << "i : " << i<< '\n';
        }
        // res+=Augment(i);
    }
    return res;
}
/*
사용 방법 : 왼쪽 집합 L에서 각각의 정점과 연결된 집합 R의 원소를 G에 채운다.
만약 L에서 2번 정점이 R에서 1, 3번과 연결되면, G[2]에 1과 3을 push_back한다.
*/
vector<string> arr;
void init(){
    arr.clear();
    for(int i=0; i<MN; ++i){
        G[i].clear();
    }
}
int dx[6]={-1,-1,-1,1,1,1};
int dy[6]={-1,0,1,-1,0,1};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        init();
        int R,C; cin>>R>>C; N=R*C-1;
        int total=0;
        for(int i=0; i<R; ++i){
            string str; cin>>str;
            arr.push_back(str);
        }
        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                if(arr[i][j]=='x') continue;
                total++;
                if(j%2==0) continue;
                for(int k=0; k<6; ++k){
                    int x=j+dx[k];
                    int y=i+dy[k];
                    if(x>=0 && x<C && y>=0 && y<R && arr[y][x]=='.'){
                        G[i*C+j].push_back(y*C+x);
                    } 
                }
            }
        }
        cout << total-Match() << '\n';
    }
}
