#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M; cin>>N>>M;
    vector<int> s, s2;
    for(int i=1; i<=N; ++i){
        int a; cin>>a;
        vector<int> temp;
        while(--a){
            temp.push_back(s.back());
            s.pop_back();
        }
        s.push_back(i);
        while(!temp.empty()){
            s.push_back(temp.back());
            temp.pop_back();
        }
    }
    // for(auto it:s){
    //     cout << it << '\n';
    // }
    for(int i=0; i<M; ++i){
        int a; cin>>a;
        vector<int> temp;
        while(--a){
            temp.push_back(s2.back());
            s2.pop_back();
        }
        s2.push_back(s[N-M+i]);
        while(!temp.empty()){
            s2.push_back(temp.back());
            temp.pop_back();
        }
    }
    for(int i=0; i<3; ++i){
        cout << s2.back() << '\n';
        s2.pop_back();
    }
}