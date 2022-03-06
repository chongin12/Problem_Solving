#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int sq;
int res[100001];
int tarr[1000001]={};
struct Query {
    int idx, s, e;
    Query(int idx, int s, int e):idx(idx),s(s),e(e){}
};
vector<Query> qv;
bool cmp(Query q1, Query q2){
    if(q1.s/sq == q2.s/sq) return q1.e < q2.e;
    return q1.s/sq < q2.s/sq;
}
int main(){
    int N; cin>>N;
    sq=sqrt(N);
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        v.push_back(a);
    }
    int Q; cin>>Q;
    for(int i=0; i<Q; ++i){
        int S,E; cin>>S>>E; S--,E--;
        qv.push_back(Query(i,S,E));
    }
    sort(qv.begin(), qv.end(), cmp);
    int t=0, ts=qv[0].s, te=qv[0].e;
    for(int i=ts; i<=te; ++i){
        tarr[v[i]]++;
        if(tarr[v[i]]==1) t++;
    }
    res[qv[0].idx]=t;
    for(int i=1; i<Q; ++i){
        int ns=qv[i].s, ne=qv[i].e, nidx=qv[i].idx;
        while(ts < ns) {
            tarr[v[ts]]--;
            if(tarr[v[ts]]==0) t--;
            ts++;
        }
        while(ts > ns) {
            --ts;
            tarr[v[ts]]++;
            if(tarr[v[ts]]==1) t++;
        }
        while(te < ne) {
            ++te;
            tarr[v[te]]++;
            if(tarr[v[te]]==1) t++;
        }
        while(te > ne) {
            tarr[v[te]]--;
            if(tarr[v[te]]==0) t--;
            te--;
        }
        res[nidx]=t;
    }
    for(int i=0; i<Q; ++i){
        cout << res[i] << '\n';
    }
}