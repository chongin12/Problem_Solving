#include <bits/stdc++.h>
using namespace std;
const int MN=1000001;
int visited[MN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<int> v;
    vector<int> ori(N);
    for(int i=0; i<MN; ++i) {
        visited[i]=-1;
    }
    for(int i=0; i<N; ++i) {
        cin>>ori[i];
        if(visited[ori[i]]==-1) v.push_back(ori[i]);
        visited[ori[i]]++;
    }
    sort(v.begin(), v.end());
    for(int i=v.size()-2; i>=0; --i){
        for(int j=v[i]+v[i]; j<MN; j+=v[i]){
            visited[j]+=visited[v[i]]+1;
        }
    }
    for(auto it:ori){
        cout << visited[it] << '\n';
    }
}