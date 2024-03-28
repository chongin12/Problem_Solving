#include <bits/stdc++.h>
using namespace std;
const int MN=100000;
int sz;
int N,Q;
int cnt[MN+10];
int cntcnt[400][MN+10]; // cntcnt[i][j] : i번째 buck에서 j번만큼 나온 수들의 개수
int buck[400];
int arr[MN+10];
int ori[MN+10];
int res[MN+10];
struct query {
    int s,e;
    int idx;
    query(int s, int e, int idx):s(s),e(e),idx(idx){}
};
vector<query> queries;
int maxNum, groupNum;
void cntsUp(int i) {
    int idx=i/sz;
    if(cnt[i]==buck[idx]) ++buck[idx];
    cntcnt[idx][cnt[i]]--;
    cnt[i]++;
    cntcnt[idx][cnt[i]]++;
}
void cntsDown(int i) {
    int idx=i/sz;
    cntcnt[idx][cnt[i]]--;
    cnt[i]--;
    cntcnt[idx][cnt[i]]++;
    if(cntcnt[idx][buck[idx]]==0) buck[idx]--;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>Q;
    sz=sqrt(N);
    vector<pair<int,int> > compression;
    for(int i=0; i<N; ++i) {
        int a; cin>>a;
        compression.push_back({a,i});
    }
    sort(compression.begin(), compression.end());
    int K=0;
    for(int i=0; i<compression.size(); ++i){
        if(i>0 && compression[i].first != compression[i-1].first){
            K++;
        }
        ori[K]=compression[i].first;
        arr[compression[i].second]=K;
    }
    maxNum=K;
    groupNum=maxNum/sz+1;
    for(int i=0; i<Q; ++i){
        int a,b; cin>>a>>b;
        queries.push_back(query(a-1,b-1,i));
    }
    sort(queries.begin(), queries.end(), [&](query a, query b){
        if(a.s/sz == b.s/sz) return a.e<b.e;
        return a.s/sz<b.s/sz;
    });

    int S=0, E=-1;
    for(int i=0; i<queries.size(); ++i){
        int toS=queries[i].s, toE=queries[i].e, toIdx=queries[i].idx;
        while(E<toE){
            ++E;
            cntsUp(arr[E]);
        }
        while(S>toS){
            --S;
            cntsUp(arr[S]);
        }
        while(E>toE){
            cntsDown(arr[E]);
            --E;
        }
        while(S<toS){
            cntsDown(arr[S]);
            ++S;
        }

        int maxBuckIdx=0;
        for(int j=1; j<=N/sz; ++j){
            if(buck[maxBuckIdx]<=buck[j]) maxBuckIdx=j;
        }
        int r=sz*maxBuckIdx;
        for(int j=0; j<sz && sz*maxBuckIdx+j<N; ++j){
            if(cnt[r]<=cnt[sz*maxBuckIdx+j]) r=sz*maxBuckIdx+j;
        }
        res[toIdx]=ori[r];
    }


    for(int i=0; i<Q; ++i){
        cout << res[i] << '\n';
    }
}