// boj 11375 bipartite matching
#include <bits/stdc++.h>
using namespace std;
const int MN=1000;
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
        res+=Augment(i);
    }
    return res;
}
/*
사용 방법 : 왼쪽 집합 L에서 각각의 정점과 연결된 집합 R의 원소를 G에 채운다.
만약 L에서 2번 정점이 R에서 1, 3번과 연결되면, G[2]에 1과 3을 push_back한다.
*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int K; cin>>N>>K;
    for(int i=1; i<=K; ++i){
        int r,c; cin>>r>>c;
        G[r].push_back(c);
    }
    cout << Match() << '\n';
}
