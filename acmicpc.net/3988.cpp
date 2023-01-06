#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin>>N>>K;
    vector<int> v(N);
    for(int i=0; i<N; ++i){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    deque<pair<int,int> > dq;
    int res=1987654321;
    for(int i=1; i<N; ++i){
        int t=v[i]-v[i-1];
        int idx=i-1;
        while(!dq.empty() && dq.front().second <= i-(N-K)) dq.pop_front();
        while(!dq.empty() && (dq.back().first >= t || dq.back().second<=i-(N-K))) dq.pop_back();
        dq.push_back({t,idx});
        if(i+1<N-K) continue;
        else res=min(res,dq.front().first+v[i]-v[i-(N-K)+1]);
    }
    cout << res << '\n';
}