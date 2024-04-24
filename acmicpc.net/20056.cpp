#include <bits/stdc++.h>
using namespace std;
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
struct Node {
    int r, c, m, s, d;

    bool operator==(Node &a) const {
        return r == a.r && c == a.c;
    }
};
bool comp(Node a, Node b){
    if(a.r == b.r) return a.c < b.c;
    return a.r < b.r;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, K; cin>>N>>M>>K;
    vector<Node> v;
    for(int i=0; i<M; ++i){
        int r, c, m, s, d; cin>>r>>c>>m>>s>>d;
        Node node = {r-1, c-1, m, s, d};
        v.push_back(node);
    }
    while(K--){
        // 이동하기
        for(int i=0; i<v.size(); ++i){
            // cout << "("<<v[i].r<<", "<<v[i].c<<") : "<<v[i].m<<", "<<v[i].s<<", "<<v[i].d<<'\n';
            v[i].r+=v[i].s*dx[v[i].d];
            while(v[i].r<0) v[i].r+=N;
            v[i].r%=N;
            v[i].c+=v[i].s*dy[v[i].d];
            while(v[i].c<0) v[i].c+=N;
            v[i].c%=N;
            // cout << "-> ("<<v[i].r<<", "<<v[i].c<<") : "<<v[i].m<<", "<<v[i].s<<", "<<v[i].d<<'\n';
        }
        sort(v.begin(), v.end(), comp);
        if(v.empty()) break;
        // cout << "다 이동하고\n";
        // for(auto it:v){
        //     cout << "("<<it.r<<", "<<it.c<<") : "<<it.m<<", "<<it.s<<", "<<it.d<<'\n';
        // }

        // 합칠꺼 정리하기
        vector<Node> temp; // v를 대체할 새로운 벡터
        vector<Node> temp2 = {v[0]}; // 파이어볼 합치기
        for(int i=1; i<=v.size(); ++i){
            if(i<v.size() && v[i-1]==v[i]) temp2.push_back(v[i]);
            else {
                // 지금까지 합친거 나누기
                if(temp2.size()>=2) {
                    Node k = temp2[0];
                    int odd=k.d%2, even=!(k.d%2);
                    for(int i=1; i<temp2.size(); ++i){
                        k.m += temp2[i].m;
                        k.s += temp2[i].s;
                        odd+=temp2[i].d%2;
                        even+=!(temp2[i].d%2);
                    }
                    k.m /= 5;
                    k.s /= temp2.size();
                    if(k.m==0) {
                        temp2.clear();
                        if(i<v.size()) temp2.push_back(v[i]);
                        continue;
                    }
                    if(odd==temp2.size() || even==temp2.size()){
                        temp.push_back({k.r, k.c, k.m, k.s, 0});
                        temp.push_back({k.r, k.c, k.m, k.s, 2});
                        temp.push_back({k.r, k.c, k.m, k.s, 4});
                        temp.push_back({k.r, k.c, k.m, k.s, 6});
                    }
                    else {
                        temp.push_back({k.r, k.c, k.m, k.s, 1});
                        temp.push_back({k.r, k.c, k.m, k.s, 3});
                        temp.push_back({k.r, k.c, k.m, k.s, 5});
                        temp.push_back({k.r, k.c, k.m, k.s, 7});
                    }
                }
                else {
                    temp.push_back(temp2.back());
                }
                temp2.clear();
                if(i<v.size()) temp2.push_back(v[i]);
            }
        }
        v = temp;
        // cout << "합치고\n";
        // for(auto it:v){
        //     cout << "("<<it.r<<", "<<it.c<<") : "<<it.m<<", "<<it.s<<", "<<it.d<<'\n';
        // }
    }
    // cout << "\n마지막 이동 후\n";
    // for(auto it:v){
    //     cout << "("<<it.r<<", "<<it.c<<") : "<<it.m<<", "<<it.s<<", "<<it.d<<'\n';
    // }
    int res=0;
    for(auto it:v){
        res+=it.m;
    }
    cout << res << '\n';
}