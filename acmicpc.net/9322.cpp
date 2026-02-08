#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        map<string, int> m;
        for(int i=0; i<N; ++i){
            string str; cin>>str;
            m[str]=i;
        }
        vector<int> v;
        for(int i=0; i<N; ++i){
            string str; cin>>str;
            v.push_back(m[str]);
        }
        map<int, string> res;
        for(int i=0; i<N; ++i){
            string str; cin>>str;
            res[v[i]]=str;
        }
        for(auto it:res){
            cout << it.second << ' ';
        }
        cout << '\n';
    }
}