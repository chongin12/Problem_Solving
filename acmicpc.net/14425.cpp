#include <bits/stdc++.h>
using namespace std;
set<string> s;
int main(){
    int N, M; cin>>N>>M;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        s.insert(str);
    }
    int res=0;
    for(int i=0; i<M; ++i){
        string str; cin>>str;
        if(s.find(str)!=s.end()){
            res++;
        }
    }
    cout << res << '\n';
}