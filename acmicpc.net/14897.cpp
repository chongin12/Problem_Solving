#include <bits/stdc++.h>
using namespace std;
int arr[1000011];
int res[1000011];
int cnt[1000011];
int sq;
struct Query{
    int l, r, idx;
    Query(int l, int r, int idx):l(l),r(r),idx(idx){}
};
bool cmp(Query A, Query B){
    if(A.l/sq==B.l/sq) return A.r<B.r;
    return A.l/sq<B.l/sq;
}
vector<Query> queries;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    sq=sqrt(N);
    vector<pair<int, int> > v(N);
    for(int i=0; i<N; ++i){
        cin>>v[i].first;
        v[i].second=i+1;
    }
    sort(v.begin(), v.end());
    int k=0;
    for(int i=1; i<=N; ++i){
        if(v[i].first==v[i-1].first){
            arr[v[i].second]=k;
        }
        else{
            arr[v[i].second]=++k;
        }
    }
    int Q; cin>>Q;
    for(int i=0; i<Q; ++i){
        int a,b; cin>>a>>b;
        queries.push_back(Query(a,b,i));
    }
    sort(queries.begin(), queries.end(), cmp);
    int L=queries[0].l, R=queries[0].r;
    int temp=0;
    for(int i=L; i<=R; ++i){
        cnt[arr[i]]++;
        if(cnt[arr[i]]==1) temp++;
    }
    res[queries[0].idx]=temp;
    for(int i=1; i<queries.size(); ++i){
        while(L<queries[i].l){
            cnt[arr[L]]--;
            if(cnt[arr[L]]==0) temp--;
            L++;
        }
        while(L>queries[i].l){
            L--;
            cnt[arr[L]]++;
            if(cnt[arr[L]]==1) temp++;
        }
        while(R>queries[i].r){
            cnt[arr[R]]--;
            if(cnt[arr[R]]==0) temp--;
            R--;
        }
        while(R<queries[i].r){
            R++;
            cnt[arr[R]]++;
            if(cnt[arr[R]]==1) temp++;
        }
        res[queries[i].idx]=temp;
    }
    for(int i=0; i<Q; ++i){
        cout << res[i] << '\n';
    }
}