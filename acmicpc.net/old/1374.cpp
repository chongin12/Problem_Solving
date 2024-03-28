#include <bits/stdc++.h>
using namespace std;
struct node {
    int a,b,c;
    node(int a, int b, int c):a(a),b(b),c(c){}
};
vector<node> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a,b,c; cin>>a>>b>>c;
        v.push_back(node(a,b,c));
    }
    sort(v.begin(), v.end(), [](node a, node b){
        return a.b<b.b;
    });
    priority_queue<int, vector<int>, greater<int> > pq;
    for(auto it:v){
        // cout << it.a << ", " << it.b << ", " << it.c << '\n';
        if(!pq.empty() && pq.top()<=it.b){
            pq.pop();
        }
        pq.push(it.c);
    }
    cout << pq.size() << '\n';
}