#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    map<string, bool> m;
    m["ChongChong"]=1;
    for(int i=0; i<N; ++i){
        string s1, s2; cin>>s1>>s2;
        if(m[s1] || m[s2]){
            m[s1]=1;
            m[s2]=1;
        }
    }
    int cnt=0;
    for(auto it=m.begin(); it!=m.end(); ++it){
        if(it->second) cnt++;
    }
    cout << cnt << '\n';
}