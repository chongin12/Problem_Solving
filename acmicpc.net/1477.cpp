#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int N, M, L;
int f(int x){ // 가능하면 true, 아니면 false
    int p=0;
    int sum=0;
    for(auto it:v){
        sum+=(it-p-1)/x;
        p=it;
    }
    if(sum>M) return false;
    return true;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M>>L;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    v.push_back(L);
    sort(v.begin(), v.end());
    int l=0, r=L;
    while(l<r-1){
        int mid=l+r>>1;
        if(f(mid)) r=mid;
        else l=mid;
    }
    cout << r << '\n';
}