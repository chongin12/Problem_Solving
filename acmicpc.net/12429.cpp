#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
pii arr[11];
int visited[11];
int N;
int res=0;
void f(int acc){
    res=max(res,acc);
    for(int i=0; i<N; ++i){
        if(visited[i]) continue;
        if(arr[i].first<acc) continue;
        visited[i]=1;
        f(acc+arr[i].second);
        visited[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        cout << "Case #"<<t<<": ";
        cin>>N;
        for(int i=0; i<N; ++i){
            int p, s; cin>>p>>s;
            arr[i]={p,s};
        }
        f(0);
        cout << res << '\n';
        res=0;
    }
}