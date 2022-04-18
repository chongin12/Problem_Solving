#include <bits/stdc++.h>
using namespace std;
struct node {
    string str;
    int n;
    node(string str, int n):str(str),n(n){}
    int f(){
        int ret=0;
        for(auto it:str){
            if(it=='0') ret++;
        }
        return ret;
    }
};
int main(){
    int N,M; cin>>N>>M;
    map<string, int> m;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        m[str]++;
    }
    int K; cin>>K;
    vector<node> v;
    for(auto it:m){
        v.push_back(node(it.first, it.second));
    }
    sort(v.begin(), v.end(), [](node A, node B){ return A.n>B.n; });
    for(auto it:v){
        if(it.f()%2 == K%2 && it.f() <= K){
            cout << it.n << '\n';
            return 0;
        }
    }
    cout << "0\n";
}