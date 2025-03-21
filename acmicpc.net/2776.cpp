#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        set<int> s;
        for(int i=0; i<N; ++i){
            int a; cin>>a;
            s.insert(a);
        }
        int M; cin>>M;
        for(int i=0; i<M; ++i){
            int a; cin>>a;
            if(s.find(a)!=s.end()) cout << "1\n";
            else cout << "0\n";
        }
    }
}