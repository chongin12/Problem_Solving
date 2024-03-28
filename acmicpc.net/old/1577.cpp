#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
struct node{
    ll a,b,c,d;
    node(ll a, ll b, ll c, ll d):a(a),b(b),c(c),d(d){}
    bool isEqual(const node &t){
        if(t.a==a && t.b==b && t.c==c && t.d==d) return true;
        return false;
    }
};

vector<node> construct;
ll dp[102][102];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,M; cin>>N>>M;
    int K; cin>>K;
    for(int i=0; i<K; ++i){
        ll a,b,c,d; cin>>a>>b>>c>>d;
        if(pii(a,b)>pii(c,d)){
            swap(a,c);
            swap(b,d);
        }
        construct.push_back(node(a,b,c,d));
    }
    dp[0][0]=1;
    for(int i=1; i<=N+M; ++i){
        for(int j=0; j<=i; ++j){
            int k=i-j;
            if(j>N || k>M) continue;
            //현재 (j,k)
            if(j-1>=0){//위
                bool flag=true;
                for(int w=0; w<K; ++w){
                    if(construct[w].isEqual(node(j-1,k,j,k))) flag=false;
                }
                if(flag) dp[j][k]+=dp[j-1][k];
            }
            if(k-1>=0){//왼쪽
                bool flag=true;
                for(int w=0; w<K; ++w){
                    if(construct[w].isEqual(node(j,k-1,j,k))) flag=false;
                }
                if(flag) dp[j][k]+=dp[j][k-1];
            }
        }
    }
    cout << dp[N][M] << '\n';
}