#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int N, M; 
int f(int x){
    int grp=1;
    int tmp=v[0];
    if(tmp>x) return 0;
    for(int i=1; i<v.size(); ++i){
        if(tmp+v[i]>x){
            grp++; tmp=v[i];
        }
        else tmp+=v[i];
        if(tmp>x || grp>M) return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for(int i=0,a; i<N; ++i){
        cin>>a; v.push_back(a);
    }
    int lo=0, hi=30000;
    while(lo<hi-1){
        int mid=lo+hi>>1;
        if(f(mid)) hi=mid;
        else lo=mid;
    }
    cout << hi << '\n';
    int cnt=1;
    int tmp=v[0];
    int acc=0;
    for(int i=1; i<N; ++i){
        if(tmp+v[i]>hi || acc+1+N-i==M){
            acc++;
            cout << cnt << ' ';
            cnt=1;
            tmp=v[i];
        }
        else {
            tmp+=v[i];
            cnt++;
        }
    }
    cout << cnt << '\n';
}