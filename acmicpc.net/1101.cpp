#include <bits/stdc++.h>
using namespace std;
int chk[51]={0,};
int main(){
    int N, M; cin>>N>>M;
    int res=0;
    for(int i=0; i<N; ++i){
        vector<int> v;
        for(int j=0; j<M; ++j){
            int a; cin>>a;
            if(a) v.push_back(j);
        }
        if(v.size()==0) continue;
        if(v.size()==1 && !chk[v[0]]) {
            chk[v[0]]=1;
            continue;
        }
        res++;
    }
    cout << max(0,res-1) << '\n';
}