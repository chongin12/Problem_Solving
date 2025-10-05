#include <bits/stdc++.h>
using namespace std;
int cnt=0;
set<int> s[101];
int main(){
    int N, E; cin>>N>>E;
    while(E--){
        int K; cin>>K;
        vector<int> v;
        for(int i=0; i<K; ++i){
            int a; cin>>a; v.push_back(a);
        }
        sort(v.begin(), v.end());
        if(v[0]==1){
            ++cnt;
            for(int i=1; i<v.size(); ++i){
                s[v[i]].insert(cnt);
            }
        }   
        else {
            set<int> temp;
            for(int i=0; i<v.size(); ++i){
                for(auto it:s[v[i]]){
                    temp.insert(it);
                }
            }
            for(int i=0; i<v.size(); ++i){
                for(auto it:temp){
                    s[v[i]].insert(it);
                }
            }
        }
    }
    cout << "1\n";
    for(int i=2; i<=N; ++i){
        if(s[i].size()==cnt){
            cout << i << '\n';
        }
    }
}