#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll INF=1987654321*270000LL;
ll tree[270000];
int N;
struct node {
    ll maxLevel;
    ll maxValue;
    ll left[20][20];
    ll right[20][20];
    ll sum[20][20];
    node(ll maxLevel):maxLevel(maxLevel){
        maxValue=-INF;
        for(int i=0; i<20; ++i){
            for(int j=0; j<20; ++j){
                left[i][j]=-INF;
                right[i][j]=-INF;
                sum[i][j]=-INF;
            }
        }
    }
};
node dfs(int x, int level){
    node ret=node(level);
    if(x*2>N){
        ret.left[level][level]=tree[x];
        ret.right[level][level]=tree[x];
        ret.sum[level][level]=tree[x];
        ret.maxValue=tree[x];
        return ret;
    }
    node lnode=dfs(x*2, level+1);
    node rnode=dfs(x*2+1, level+1);
    ret.maxLevel=lnode.maxLevel;
    ret.maxValue=max(lnode.maxValue, rnode.maxValue);
    for(int i=level+1; i<=ret.maxLevel; ++i){
        for(int j=i; j<=ret.maxLevel; ++j){
            ret.left[i][j]=max(lnode.left[i][j], lnode.sum[i][j]+rnode.left[i][j]);
            ret.right[i][j]=max(rnode.right[i][j], rnode.sum[i][j]+lnode.right[i][j]);
            ret.sum[i][j]=lnode.sum[i][j]+rnode.sum[i][j];

            ret.maxValue=max({ret.maxValue, ret.left[i][j], ret.right[i][j], lnode.right[i][j]+rnode.left[i][j], lnode.right[i][j], rnode.left[i][j]});
        }
    }
    ret.maxValue=max(ret.maxValue, tree[x]);
    ret.left[level][level]=tree[x];
    ret.right[level][level]=tree[x];
    ret.sum[level][level]=tree[x];
    for(int i=level+1; i<=ret.maxLevel; ++i){
        ret.left[level][i]=max({lnode.left[level+1][i], lnode.sum[level+1][i]+tree[x], lnode.sum[level+1][i]+tree[x]+rnode.left[level+1][i]});
        ret.right[level][i]=max({rnode.right[level+1][i], rnode.sum[level+1][i]+tree[x], rnode.sum[level+1][i]+tree[x]+lnode.right[level+1][i]});
        ret.sum[level][i]=lnode.sum[level+1][i]+rnode.sum[level+1][i]+tree[x];

        ret.maxValue=max({ret.maxValue, lnode.right[level+1][i]+tree[x], lnode.right[level+1][i]+tree[x]+rnode.left[level+1][i], tree[x]+rnode.left[level+1][i]});
    }
    // cout << "in node "<<x<<"\n";
    // cout << "max value : " << ret.maxValue << '\n';
    // for(int i=level; i<=ret.maxLevel; ++i){
    //     for(int j=i; j<=ret.maxLevel; ++j){
    //         cout << "ret.left["<<i<<"]["<<j<<"]="<<ret.left[i][j]<<'\n';
    //         cout << "ret.right["<<i<<"]["<<j<<"]="<<ret.right[i][j]<<'\n';
    //         cout << "ret.sum["<<i<<"]["<<j<<"]="<<ret.sum[i][j]<<'\n';
    //     }
    // }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    ll ans=-1987654321;
    for(int i=1; i<=N; ++i) {
        cin>>tree[i];
        ans=max(ans,tree[i]);
    }
    node res=dfs(1, 0);
    cout << res.maxValue << '\n';

}