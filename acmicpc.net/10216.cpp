#include <bits/stdc++.h>
using namespace std;
struct Node {
    int x, y, R;
};
int p[3001];
void init(){
    for(int i=0; i<3001; ++i){
        p[i]=i;
    }
}
int Find(int x){
    if(p[x]==x) return x;
    return p[x]=Find(p[x]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    p[a]=b;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        init();
        int N; cin>>N;
        vector<Node> v;
        for(int i=0; i<N; ++i){
            int x, y, R; cin>>x>>y>>R;
            for(int j=0; j<v.size(); ++j){
                auto it=v[j];
                if((x-it.x)*(x-it.x)+(y-it.y)*(y-it.y)<=(R+it.R)*(R+it.R)){
                    Union(i, j);
                }
            }
            v.push_back({x,y,R});
        }
        set<int> s;
        for(int i=0; i<N; ++i){
            s.insert(Find(i));
        }
        cout << s.size() << '\n';
    }
}