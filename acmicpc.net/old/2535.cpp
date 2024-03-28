#include <bits/stdc++.h>
using namespace std;
struct node {
    int a,b,c;
    node(int a, int b, int c):a(a),b(b),c(c){}
};
vector<node> v;
int visited[1001];
int main(){
    int N; cin>>N;
    int cont=0;
    for(int i=0; i<N; ++i){
        int a,b,c; cin>>a>>b>>c;
        v.push_back(node(a,b,c));
    }
    sort(v.begin(), v.end(), [](node a, node b){
        return a.c>b.c;
    });
    int goal=0;
    for(int i=0; i<v.size() && goal<3; ++i){
        if(visited[v[i].a]>=2) continue;
        visited[v[i].a]++;
        cout << v[i].a << " " << v[i].b << '\n';
        goal++;
    }
}