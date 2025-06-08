#include <bits/stdc++.h>
using namespace std;
using psi=pair<string,int>;
string toString(vector<int> v){
    string ret="";
    for(auto it:v) ret+=to_string(it);
    return ret;
};
map<string, int> m;
struct Node {
    int x, y, w;
};
struct comp {
    bool operator()(psi a, psi b){
        return a.second > b.second;
    }
};
vector<Node> ctrls;
priority_queue<psi, vector<psi>, comp> q;
int main(){
    int N; cin>>N;
    vector<int> ori, v;
    for(int i=0; i<N; ++i){
        int a; cin>>a; a--;
        ori.push_back(a); v.push_back(a);
    }
    sort(v.begin(), v.end());
    string goal=toString(v);
    int M; cin>>M;
    for(int i=0; i<M; ++i){
        int x, y, w; cin>>x>>y>>w;
        x--, y--;
        ctrls.push_back({x,y,w});
    }
    q.push({toString(ori), 0});
    m[toString(ori)]=0;
    while(!q.empty()){
        auto cur = q.top(); q.pop();
        // cout << "cur : " << cur.first << ", " << cur.second << '\n';
        if(cur.first==goal){
            cout << cur.second << '\n';
            return 0;
        }
        if(m[cur.first]!=cur.second){
            continue;
        }
        for(auto it:ctrls){
            string temp=cur.first;
            swap(temp[it.x], temp[it.y]);
            if(m.find(temp)==m.end() || m[temp]>cur.second+it.w){
                m[temp]=cur.second+it.w;
                q.push({temp, cur.second+it.w});
            }
        }
    }
    cout << "-1\n";
}