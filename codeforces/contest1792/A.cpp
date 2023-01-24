#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        vector<int> v(N);
        for(int i=0; i<N; ++i){
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        if(v[0]!=1){
            cout << v.size() << '\n';
            continue;
        }
        int cnt=0;
        int i;
        for(i=1; i<v.size(); i+=2){
            if(v[i-1]==1 && v[i]==1) cnt+=1;
            else{
                break;
            }
        }
        cnt+=v.size()-i+1;
        cout << cnt << '\n';
    }
}