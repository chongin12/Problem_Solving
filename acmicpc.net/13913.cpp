#include <bits/stdc++.h>
using namespace std;
const int MN = 200011;
int visited[MN];
int R[MN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin>>N>>K;
    queue<int> q;
    q.push(N);
    visited[N]=1;
    R[N]=N;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur == K) {
            break;
        }
        if(cur+1<MN && !visited[cur+1]) {
            q.push(cur+1);
            visited[cur+1]=1;
            R[cur+1]=cur;
        }
        if(cur-1>=0 && !visited[cur-1]) {
            q.push(cur-1);
            visited[cur-1]=1;
            R[cur-1]=cur;
        }
        if(cur*2<MN && !visited[cur*2]) {
            q.push(cur*2);
            visited[cur*2]=1;
            R[cur*2]=cur;
        }
    }
    vector<int> v = {K};
    while(v.back() != R[v.back()]) {
        v.push_back(R[v.back()]);
    }
    reverse(v.begin(), v.end());
    cout << v.size() - 1 << '\n';
    for(auto it:v){
        cout << it << " ";
    }
    cout << '\n';
}