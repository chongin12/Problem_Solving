#include <bits/stdc++.h>
using namespace std;
const int MN=10000;
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
int Match(int N){
    int res=0;
    fill(R.begin(), R.end(), -1);
    for(int i=1; i<=N; ++i){
        fill(C.begin(), C.end(), 0);
        res+=Augment(i);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,M; cin>>N>>M;
    for(int i=1; i<=N; ++i){
        int k; cin>>k;
        for(int j=0; j<k; ++j){
            int a; cin>>a;
            G[i].push_back(a);
        }
    }
    cout << Match(N) << '\n';
}