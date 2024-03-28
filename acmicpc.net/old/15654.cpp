#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int N, M; 
void f(int c, vector<int> k, int visited[10]) {
    if(c==M-1){
        for(auto it:k){
            cout << v[it] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=0; i<N; ++i){
        if(visited[i]) continue;
        vector<int> temp = k;
        int vis[10];
        copy(visited, visited+10, vis);
        temp.push_back(i);
        vis[i]=1;
        f(c+1,temp, vis);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        int a; cin >> a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<N; ++i){
        vector<int> t;
        t.push_back(i);
        int visited[10] = {};
        visited[i] = 1;
        f(0, t, visited);
    }
}