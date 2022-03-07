#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int sq;
int ans[100001];
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
int f(map<int, int> m){
    int res=0;
    for(auto it:m){
        res=max(res, it.second);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
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
    int arr[100001] = {}; // arr[i] = j 라면 i가 j번 등장한다는 뜻.
    int cntcnt[100001] = {}; // cntcnt[i] = j 라면 i번 등장하는 수가 j개 있다는 뜻.
    int res=0, resmax=0;
    // res는 현재 가장 많이 등장하는 수들의 개수. 0이 되면 새로운 res를 찾아야 함. cntcnt[i]의 최대값
    // resmax는 현재 가장 많이 등장하는 수들이 등장한 횟수. arr[i]의 최대값.
    int s=qv[0].s, e=qv[0].e;
    cntcnt[0] = 100000;
    resmax=0;
    res=cntcnt[0];
    for(int i=s; i<=e; ++i){
        cntcnt[arr[v[i]]]--;
        arr[v[i]]++;
        cntcnt[arr[v[i]]]++;
        if(resmax < arr[v[i]]){
            resmax=arr[v[i]];
            res=1;
        }
        else if(resmax == arr[v[i]]) {
            res=cntcnt[arr[v[i]]];
        }
    }
    ans[qv[0].idx]=resmax;
    // cout << "s : " << s << ", e : " << e << ", res : " << res << ", resmax : " << resmax << '\n';
    for(int i=1; i<Q; ++i){
        while(s < qv[i].s){
            cntcnt[arr[v[s]]]--;
            arr[v[s]]--;
            cntcnt[arr[v[s]]]++;
            if(res==1 && arr[v[s]]+1==resmax){
                resmax=arr[v[s]];
                res=cntcnt[arr[v[s]]];
            }
            else if(arr[v[s]]+1==resmax){
                res--;
            }
            s++;
        }
        while(s > qv[i].s) {
            --s;
            cntcnt[arr[v[s]]]--;
            arr[v[s]]++;
            cntcnt[arr[v[s]]]++;
            if(resmax < arr[v[s]]){
                resmax=arr[v[s]];
                res=1;
            }
            else if(resmax == arr[v[s]]) {
                res=cntcnt[arr[v[s]]];
            }
        }
        while(e < qv[i].e) {
            ++e;
            cntcnt[arr[v[e]]]--;
            arr[v[e]]++;
            cntcnt[arr[v[e]]]++;
            if(resmax < arr[v[e]]){
                resmax=arr[v[e]];
                res=1;
            }
            else if(resmax == arr[v[e]]) {
                res=cntcnt[arr[v[e]]];
            }
        }
        while(e > qv[i].e) {
            cntcnt[arr[v[e]]]--;
            arr[v[e]]--;
            cntcnt[arr[v[e]]]++;
            if(res==1 && arr[v[e]]+1==resmax){
                resmax=arr[v[e]];
                res=cntcnt[arr[v[e]]];
            }
            else if(arr[v[e]]+1==resmax){
                res--;
            }
            e--;
        }
        // cout << "s : " << s << ", e : " << e << ", res : " << res << ", resmax : " << resmax << '\n';
        ans[qv[i].idx] = resmax;
    }
    for(int i=0; i<Q; ++i){
        cout << ans[i] << '\n';
    }
}