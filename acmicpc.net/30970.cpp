#include <bits/stdc++.h>
using namespace std;
struct Node {
    int Q, P, idx;
};
vector<Node> v;
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int Q, P; cin>>Q>>P;
        v.push_back({Q,P,i+1});
    }
    sort(v.begin(), v.end(), [](Node a, Node b){
        if(a.Q==b.Q) return a.P<b.P;
        return a.Q>b.Q;
    });
    cout << v[0].Q << " " << v[0].P << " " << v[1].Q << " " << v[1].P << '\n';
    sort(v.begin(), v.end(), [](Node a, Node b){
        if(a.P==b.P) return a.Q>b.Q;
        return a.P<b.P;
    });
    cout << v[0].Q << " " << v[0].P << " " << v[1].Q << " " << v[1].P << '\n';
}