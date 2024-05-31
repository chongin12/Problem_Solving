#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int N, K; 
int f(int x){ // v를 K개의 그룹으로 쪼갤 건데 한 그룹이 최소 x가 되도록 쪼갤 수 있는지.
    int acc=0;
    int groups=0;
    for(auto it:v){
        acc+=it;
        if(acc>=x) {
            groups++;
            acc=0;
        }
    }
    if(groups>=K) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>K;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    int lo = 0, hi=N*20+1;
    while(lo<hi-1){
        int mid = (lo+hi)/2;
        if(f(mid)) lo=mid;
        else hi=mid;
    }
    cout << lo << '\n';
}