#include <bits/stdc++.h>
using namespace std;
struct Node {
    int a, b, c, n, rank;
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin>>N>>K;
    vector<Node> v;
    for(int i=0; i<N; ++i){
        int n, a, b, c; cin>>n>>a>>b>>c;
        v.push_back({a,b,c,n,-1});
    }
    sort(v.begin(), v.end(), [](Node a, Node b){
        if(a.a == b.a) {
            if(a.b == b.b) {
                return a.c > b.c;
            }
            return a.b > b.b;
        }
        return a.a > b.a;
    });
    v[0].rank = 1;
    if(v[0].n == K){
        cout << "1\n";
        return 0;
    }
    for(int i=1; i<v.size(); ++i){
        if(v[i].a==v[i-1].a && v[i].b==v[i-1].b && v[i].c==v[i-1].c){
            v[i].rank = v[i-1].rank;
        }
        else {
            v[i].rank = i+1;
        }
        if(v[i].n == K) {
            cout << v[i].rank << '\n';
            return 0;
        }
    }
}