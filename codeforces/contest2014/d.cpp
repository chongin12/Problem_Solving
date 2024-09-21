#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        vector<int> v(100010), acc(100010);
        int n, d, k; cin>>n>>d>>k;
        for(int i=0; i<k; ++i){
            int l, r; cin>>l>>r;
            l=max(1,l-(d-1));
            v[l]+=1;
            v[r+1]-=1;
        }
        int minDay=1, maxDay=1;
        for(int i=1; i<=n-d+1; ++i){
            acc[i]=acc[i-1]+v[i];
            if(acc[minDay]>acc[i]){
                minDay=i;
            }
            if(acc[maxDay]<acc[i]){
                maxDay=i;
            }
        }
        cout << maxDay << " " << minDay << '\n';
    }
}