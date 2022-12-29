#include <bits/stdc++.h>
using namespace std;
const int MN=10000;
int N,M;
vector<int> G[MN]; // G[u] : u와 연결된 정점 v의 리스트. 단, u는 L에, v는 R에 속함.
vector<int> R(MN); // R[v] : v와 연결된 정점 u의 리스트. 단, u는 L에, v는 R에 속하며, 없으면 -1.
vector<int> L(MN); // L[u] : R[v]=u일 때 L[u]=v
vector<int> C(MN); // C[v] : 증가 경로를 찾을 때 v를 방문했으면 1
bool Augment(int v){ // u에서 시작하는 증가 경로가 있으면 true
    for(auto i:G[v]){
        if(C[i]) continue; C[i]=1;
        if(R[i]==-1 || Augment(R[i])){
            L[v]=i; R[i]=v; return true;
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
void DFS(int v){
    if(v==-1 || C[v]) return; C[v]=1;
    for(auto i:G[v]) C[N+i]=1, DFS(R[i]);
}
pair<vector<int>, vector<int>> VertexCover(){
    fill(L.begin(), L.end(), -1);
    fill(R.begin(), R.end(), -1);
    for(int i=1; i<=N; ++i){
        fill(C.begin(), C.end(), 0);
        Augment(i);
    }
    vector<int> res1,res2;
    fill(C.begin(), C.end(), 0);
    for(int i=1; i<=N; ++i){
        if(L[i]==-1) DFS(i);
    }
    for(int i=1; i<=N; ++i){
        if(!C[i]) res1.push_back(i);
    }
    for(int i=1; i<=M; ++i){
        if(C[N+i]) res2.push_back(i);
    }
    return {res1,res2};
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for(int i=1; i<=N; ++i){
        int k; cin>>k;
        for(int j=0; j<k; ++j){
            int a; cin>>a;
            G[i].push_back(a);
        }
    }
    pair<vector<int>, vector<int>> pvv = VertexCover();
    cout << pvv.first.size()+pvv.second.size() << '\n';
    cout << pvv.first.size() << ' ';
    for(auto it:pvv.first){
        cout << it << " ";
    }
    cout << '\n';
    cout << pvv.second.size() << ' ';
    for(auto it:pvv.second){
        cout << it << " ";
    }
    cout << '\n';

}