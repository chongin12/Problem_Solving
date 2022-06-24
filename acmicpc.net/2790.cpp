#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin>>N;
    vector<int> v(N);
    vector<int> v2(N);
    for(int i=0; i<N; ++i) cin>>v[i];
    sort(v.begin(), v.end(), greater<int>());
    for(int i=0; i<N; ++i){
        v2[i]=v[i]+i+1;
    }
    int temp=v2[0];
    int cnt=1;
    for(int i=1; i<N; ++i){
        if(v[i]+N<temp) break;
        cnt++;
        if(v2[i]>temp) temp=v2[i];
    }
    cout << cnt << '\n';
}