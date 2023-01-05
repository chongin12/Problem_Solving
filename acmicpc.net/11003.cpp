#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,L; cin>>N>>L;
    deque<pii> dq;
    for(int i=1; i<=N; ++i){
        int a; cin>>a;
        while(!dq.empty() && (dq.front().first>=a || dq.front().second<i-L+1)) dq.pop_front();
        while(!dq.empty() && (dq.back().first>=a || dq.back().second<i-L+1)) dq.pop_back();
        if(!dq.empty() && dq.front().first>=a) dq.push_front({a,i});
        else dq.push_back({a,i});
        cout << dq.front().first << " ";
    }
    cout << '\n';
}