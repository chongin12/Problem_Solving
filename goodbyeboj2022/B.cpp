#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int psum[100002];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<int> v(N);
    for(int i=0; i<N; ++i){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    double res=0;
    double sum=v[(N-1)/2];
    int l=(N-1)/2-1, r=(N-1)/2+1;
    double sz=1;
    bool phase=true; // true면 오른쪽부터
    if(N%2) phase=false;
    while(1){
        res=max(res,sum/sz);
        if(l==-1 && r==N) break;
        if(phase){
            sum+=v[r++];
            sz+=1;
        }
        else{
            sum+=v[l--];
            sz+=1;
        }
        phase=!phase;
    }
    cout.precision(7);
    cout << fixed;
    cout << res << '\n';
}