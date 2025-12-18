#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int arr[2000][2000];
int cnt[2000];
int main(){
    int N, T, P; cin>>N>>T>>P; P--;
    for(int i=0; i<N; ++i){
        for(int j=0; j<T; ++j){
            cin>>arr[i][j];
            cnt[j]+=arr[i][j];
        }
    }
    for(int j=0; j<T; ++j){
        cnt[j]=N-cnt[j];
    }
    vector<pii> v; // {스코어, 문제 개수}
    for(int i=0; i<N; ++i){
        v.push_back({0,0});
        for(int j=0; j<T; ++j){
            if(arr[i][j]) {
                v[i].first+=cnt[j];
                v[i].second++;
            }
        }
    }
    int res=0;
    for(int i=0; i<P; ++i){
        if(v[i].first>v[P].first) res++;
        else if(v[i].first==v[P].first && v[i].second>=v[P].second) res++;
    }
    for(int i=P+1; i<N; ++i){
        if(v[i].first>v[P].first) res++;
        else if(v[i].first==v[P].first && v[i].second>v[P].second) res++;
    }
    cout << v[P].first << " " << res+1 << '\n';
}