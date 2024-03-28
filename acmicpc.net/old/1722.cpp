#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll fact[21];
ll N;
bool visited[21];
// x : 현재 노드, cnt : 남은 개수, depth : 남은 수의 개수
void q1(int x, ll cnt, int depth){
    if(x!=0) cout << x << " ";
    for(int i=1; i<=N; ++i){
        if(visited[i]) continue;
        if(cnt>fact[depth]){
            cnt-=fact[depth];
            continue;
        }
        visited[i]=1;
        q1(i,cnt,depth-1);
        return;
    }
}
int main(){
    fact[0]=1;
    for(ll i=1; i<=20; ++i){
        fact[i]=fact[i-1]*i;
    }

    cin>>N;
    int ch; cin>>ch;
    if(ch==1){
        ll k; cin>>k;
        q1(0,k,N-1);
        cout << '\n';
    }
    else{
        ll cnt=1;
        for(int a,i=1; i<=N; ++i){
            cin>>a;
            visited[a]=1;
            for(int j=1; j<a; ++j){
                if(visited[j]) continue;
                cnt+=fact[N-i];
            }
        }
        cout << cnt << '\n';
    }
}