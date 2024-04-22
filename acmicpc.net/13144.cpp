#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll chk[100001];
vector<ll> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    ll l=0, r=-1;
    ll res=0;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a;
        v.push_back(a);
        if(++chk[v[++r]]==2) {
            for(;l<r;){
                --chk[v[l++]];
                if(chk[v[r]]==1) break;
            }
        }
        res+=r-l+1;
    }
    cout << res << '\n';
}
/*
i지점에서 끝나는 연속수열이라고 가정. 그 지점을 r이라고 하자.
l지점은 i-1때의 l지점에서부터 시작해서 -> r지점을 먹었을 때 2가 생기면 그 숫자가 나올 때 까지 오른쪽으로.
-> 안나왔으면 가만히 있으면 된다.

더하는 값은 해당 길이+1만큼. 어차피 i에서 끝나야 하는 수열이므로.
만약 l=2, r=5면
2~5, 3~5, 4~5, 5~5 만 더하면 된다.
*/