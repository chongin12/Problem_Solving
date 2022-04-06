#include <bits/stdc++.h>
using namespace std;
struct Query{
    int l, r, idx;
    Query(int l, int r, int idx):l(l),r(r),idx(idx){}
};
int sq;
bool cmp(Query A, Query B){
    if(A.l/sq == B.l/sq) return A.r<B.r;
    return A.l/sq < B.l/sq;
}
vector<Query> queries;
int arr[300011];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,C; cin>>N>>C;
    sq=sqrt(N);
    for(int i=1; i<=N; ++i){
        cin>>arr[i];
    }
    int Q; cin>>Q;
    for(int i=0; i<Q; ++i){
        int a,b; cin>>a>>b;
        queries.push_back(Query(a, b, i));
    }
    sort(queries.begin(), queries.end(), cmp);
    int cnt[10001]={};
    int res[10001]={};
    int L=queries[0].l, R=queries[0].r;
    int goal=(R-L+1)/2+1;
    int goalcol=-1;
    for(int i=L; i<=R; ++i){
        ++cnt[arr[i]];
        if(cnt[arr[i]] >= goal){
            goalcol=arr[i];
        }
    }
    res[queries[0].idx]=goalcol;
    for(int i=1; i<queries.size(); ++i){
        goal=(queries[i].r-queries[i].l+1)/2+1;
        goalcol=-1;
        while(L>queries[i].l){
            --L;
            cnt[arr[L]]++;
        }
        while(L<queries[i].l){
            cnt[arr[L]]--;
            ++L;
        }
        while(R<queries[i].r){
            ++R;
            cnt[arr[R]]++;
        }
        while(R>queries[i].r){
            cnt[arr[R]]--;
            --R;
        }

        for(int i=1; i<=C; ++i){
            if(cnt[i]>=goal) {
                goalcol=i;
                break;
            }
        }
        res[queries[i].idx]=goalcol;
    }
    for(int i=0; i<Q; ++i){
        if(res[i]==-1){
            cout << "no\n";
        }
        else{
            cout << "yes " << res[i] << '\n';
        }
    }
}