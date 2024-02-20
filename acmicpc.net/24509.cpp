#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, a, b, c, d;
};
vector<node> v;
int chk[200001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int x, a, b, c, d; cin>>x>>a>>b>>c>>d;
        v.push_back({x,a,b,c,d});
    }
    sort(v.begin(), v.end(), [](node a, node b){
        if(a.a==b.a) return a.x<b.x;
        return a.a>b.a;
    });
    for(int i=0; i<N; ++i){
        if(!chk[v[i].x]){
            chk[v[i].x]=1;
            cout << v[i].x << " ";
            break;
        }
    }
    sort(v.begin(), v.end(), [](node a, node b){
        if(a.b==b.b) return a.x<b.x;
        return a.b>b.b;
    });
    for(int i=0; i<N; ++i){
        if(!chk[v[i].x]){
            chk[v[i].x]=1;
            cout << v[i].x << " ";
            break;
        }
    }
    sort(v.begin(), v.end(), [](node a, node b){
        if(a.c==b.c) return a.x<b.x;
        return a.c>b.c;
    });
    for(int i=0; i<N; ++i){
        if(!chk[v[i].x]){
            chk[v[i].x]=1;
            cout << v[i].x << " ";
            break;
        }
    }
    sort(v.begin(), v.end(), [](node a, node b){
        if(a.d==b.d) return a.x<b.x;
        return a.d>b.d;
    });
    for(int i=0; i<N; ++i){
        if(!chk[v[i].x]){
            chk[v[i].x]=1;
            cout << v[i].x << " ";
            break;
        }
    }
    cout << "\n";
}