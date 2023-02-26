#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int sum[2][7]; // arr[][j] : 위에 j눈이 나타났을 때 sum.
vector<int> v(6);
int oppo(int idx){
    if(idx==0 || idx==5) return 5-idx;
    if(idx==1 || idx==3) return 4-idx;
    return 6-idx;
}
int sideMax(int idx){
    int m=-1;
    for(int i=0; i<6; ++i){
        if(i==idx || i==oppo(idx)) continue;
        m=max(m,v[i]);
    }
    return m;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;

    
    for(int i=0; i<N; ++i){
        for(int j=0; j<6; ++j) cin>>v[j];
        if(i==0){
            for(int j=0; j<6; ++j){
                sum[1][v[oppo(j)]]=sideMax(j);
            }
        }
        else{
            for(int j=0; j<6; ++j){
                sum[(i+1)%2][v[oppo(j)]]=sum[i%2][v[j]]+sideMax(j);
            }
        }
    }
    int res=0;
    for(int i=1; i<=6; ++i){
        res=max(res,sum[N%2][i]);
    }
    cout << res << '\n';
}