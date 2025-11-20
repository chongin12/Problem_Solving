#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int s, t; cin>>s>>t;
        for(int j=0; j<t; ++j){
            string str; cin>>str;
            m[str]++;
        }
    }
    int res=0;
    vector<string> r;
    for(auto it:m){
        if(it.second>res){
            res=it.second;
            r.clear();
            r.push_back(it.first);
        }
        else if(it.second == res){
            r.push_back(it.first);
        }
    }
    if(r.size()==1) cout << r[0] << '\n';
    else cout << "-1\n";
}