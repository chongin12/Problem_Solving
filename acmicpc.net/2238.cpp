#include <bits/stdc++.h>
using namespace std;
int main(){
    int U,N; cin>>U>>N;
    vector<string> v[100001];
    for(int i=0; i<N; ++i){
        string str;
        int a;
        cin>>str>>a;
        v[a].push_back(str);
    }
    int idx=-1;
    for(int i=1; i<=U; ++i){
        if(v[i].empty()) continue;
        if(idx==-1) idx=i;
        else if(v[idx].size()>v[i].size()){
            idx=i;
        }
    }
    cout << v[idx][0] << ' ' << idx << '\n';
}