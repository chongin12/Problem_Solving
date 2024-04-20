#include <bits/stdc++.h>
using namespace std;
struct Node {
    int s, e, c;
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<Node> v;
    for(int i=0; i<N; ++i){
        int S, E, C; cin>>S>>E>>C;
        v.push_back({S,E,C});
    }
    sort(v.begin(), v.end(), [](Node a, Node b){
        return a.e < b.e;
    });
    vector<Node> res={v[0]};
    for(int i=1; i<v.size(); ++i){
        res.push_back(v[i]);
        while(res.size()>=2){
            auto back1 = res.back(); res.pop_back();
            auto back2 = res.back(); res.pop_back();
            if(back1.s <= back2.e){
                res.push_back({min(back2.s, back1.s), max(back2.e, back1.e), min(back2.c, back1.c)});
            }
            else {
                res.push_back(back2);
                res.push_back(back1);
                break;
            }
        }
    }
    cout << res.size() << '\n';
    for(auto it:res){
        cout << it.s << " " << it.e << " " << it.c << '\n';
    }
}