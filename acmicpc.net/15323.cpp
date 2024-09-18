#include <bits/stdc++.h>
using namespace std;
queue<string> q[26];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int K, N; cin>>K>>N;
    vector<string> v[26];
    for(int i=0; i<K; ++i){
        string str; cin>>str;
        v[str[0]-'a'].push_back(str);
    }
    for(int i=0; i<26; ++i){
        sort(v[i].begin(), v[i].end());
        for(auto it:v[i]){
            q[i].push(it);
        }
    }
    for(int i=0; i<N; ++i){
        char a; cin>>a;
        auto &curQ = q[a-'a'];
        cout << curQ.front() << '\n';
        curQ.push(curQ.front());
        curQ.pop();
    }
}