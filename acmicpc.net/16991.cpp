#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,double>;
double G[17][17];
vector<pair<double,double>> v;
double dp[17][1<<17];
int N;
double tsp(int cur, int visitedMask) {
    if(visitedMask==(1<<N)-1) return G[cur][0];
    if(dp[cur][visitedMask]!=0) return dp[cur][visitedMask];
    double ret=987654321;
    for(int i=0; i<N; ++i){
        if(!(visitedMask & (1<<i))) {
            ret=min(ret,tsp(i,visitedMask|(1<<i))+G[cur][i]);
        }
    }
    return dp[cur][visitedMask]=ret;
}
int main(){
    cin>>N;
    for(int i=0; i<N; ++i){
        double a,b; cin>>a>>b;
        v.push_back({a,b});
        for(int j=0; j<i; ++j){
            double distance = sqrt((v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second));
            G[i][j]=distance;
            G[j][i]=distance;
        }
    }
    cout << fixed;
    cout.precision(7);
    cout << tsp(0,1) << '\n';
}