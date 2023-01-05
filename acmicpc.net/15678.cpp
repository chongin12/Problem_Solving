// #include <bits/stdc++.h>
// using namespace std;
// using ll=long long;
// ll N, D;
// ll res=-1e18;
// struct node {
//     ll value;
//     ll idx;
//     node(ll value, ll idx):value(value), idx(idx){}
// };
// struct comp {
//     bool operator()(node a, node b){
//         return a.value<b.value;
//     }
// };
// int main(){
//     ios::sync_with_stdio(0); cin.tie(0);
//     cin>>N>>D;
//     priority_queue<node, vector<node>, comp> pq;
//     vector<ll> v(N);
//     for(ll i=0; i<N; ++i){
//         cin>>v[i];
//     }
//     for(ll i=0; i<N; ++i){
//         ll a=v[i];
//         if(pq.empty()){
//             res=max(res,a);
//             pq.push(node(a, i));
//             continue;
//         }
//         node cur = pq.top();
//         if(cur.idx < i-D){
//             --i;
//             pq.pop();
//             continue;
//         }
//         pq.push(node(a,i));
//         pq.push(node(cur.value+a,i));
//         res=max({res, cur.value+a, a});
//     }
//     cout << res << '\n';
// }

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
ll dp[100001]; // dp[i] : i번째 다리를 선택했을 때 누적 최댓값

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N,D; cin>>N>>D;
    ll res=-987654321;
    deque<ll> dq; // front는 dp[idx]가 최댓값인 idx으로.
    for(int i=0; i<N; ++i){
        ll a; cin>>a;
        while(!dq.empty() && dq.front()<i-D) dq.pop_front();
        if(dq.empty() || dp[dq.front()]<=0) dp[i]=a;
        else dp[i]=dp[dq.front()]+a;
        if(dq.empty() || dp[dq.front()]<=dp[i]){
            dq.push_front(i);
        }
        else{
            while(!dq.empty() && (dq.back()<i-D || dp[dq.back()]<=dp[i])) dq.pop_back();
            dq.push_back(i);
        }
        res=max(res,dp[i]);
    }
    cout << res << '\n';
}