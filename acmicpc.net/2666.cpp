#include <bits/stdc++.h>
using namespace std;
const int INF = 999;
int N;
vector<bool> v(21, 1);
vector<int> query;
int f(int phase) {
    if(phase==query.size()){
        return 0;
    }
    int pos = query[phase];
    int cnt=0;
    int ret=INF;
    for(int i=pos; i>0; --i, cnt++){
        if(!v[i]) break;
        if(i==1) cnt=INF;
    }
    if(cnt==0){
        ret=min(ret, f(phase+1));
    }
    else if(cnt<INF){
        v[pos-cnt]=1;
        v[pos]=0;
        ret=min(ret, cnt + f(phase+1));
        v[pos]=1;
        v[pos-cnt]=0;
    }
    cnt=1;
    for(int i=pos+1; i<=N; ++i, cnt++){
        if(!v[i]) break;
        if(i==N) cnt=INF;
    }
    if(pos+1>N) cnt=INF;
    if(cnt<INF){
        v[pos+cnt]=1;
        v[pos]=0;
        ret=min(ret, cnt + f(phase+1));
        v[pos]=1;
        v[pos+cnt]=0;
    }
    return ret;
}
int main(){
    cin>>N;
    int a, b; cin>>a>>b;
    v[a]=0, v[b]=0;
    int k; cin>>k;
    for(int i=0; i<k; ++i){
        int w; cin>>w;
        query.push_back(w);
    }
    cout << f(0) << '\n';
}