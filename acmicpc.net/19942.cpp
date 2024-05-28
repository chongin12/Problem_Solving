#include <bits/stdc++.h>
using namespace std;
struct Node {
    int p, f, s, v, c;
};
vector<Node> v;
const int INF = 987654321;
int main(){
    int N; cin>>N;
    int mp, mf, ms, mv; cin>>mp>>mf>>ms>>mv;
    for(int i=0; i<N; ++i){
        int a, b, c, d, e; cin>>a>>b>>c>>d>>e;
        v.push_back({a, b, c, d, e});
    }
    Node res={0,0,0,0,INF};
    vector<int> resv;
    for(int i=0; i<(1<<(N)); ++i) {
        Node a={0,0,0,0,0};
        vector<int> vv;
        for(int j=0; (1<<j)<=i; ++j) {
            if(i&(1<<j)) {
                a.p += v[j].p;
                a.f += v[j].f;
                a.s += v[j].s;
                a.v += v[j].v;
                a.c += v[j].c;
                vv.push_back(j+1);
            }
        }
        if(a.p>=mp && a.f>=mf && a.s>=ms && a.v>=mv && res.c>=a.c){
            if(res.c == a.c) {
                if(resv.empty()){
                    res = a;
                    resv = vv;
                }
                else {
                    bool flag=true;
                    for(int k=0; k<vv.size(); ++k){
                        if(resv.size()==k) {
                            flag=false;
                            break;
                        }
                        if(resv[k] < vv[k]) {
                            flag=false;
                            break;
                        }
                        if(resv[k]>vv[k]){
                            flag=true;
                            break;
                        }
                    }
                    if(flag){
                        res = a;
                        resv = vv;
                    }
                }
            }
            else {
                res = a;
                resv = vv;
            }
        }
    }
    if(res.c==INF) cout << "-1\n";
    else {
        cout << res.c << '\n';
        for(auto it:resv){
            cout << it << ' ';
        }
        cout << '\n';
    }
}