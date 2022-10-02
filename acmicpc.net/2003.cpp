#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,M; cin>>N>>M;
    vector<int> v;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        v.push_back(a);
    }
    int s=0, e=0; // s~e
    int acc=v[0];
    int res=0;
    while(s<N && e<N){
        if(M==acc) {
            res++;
            acc-=v[s];
            s++;
            e++;
            acc+=v[e];
        }
        else if(M>acc){
            e++;
            if(e==N) break;
            acc+=v[e];
        }
        else{
            acc-=v[s];
            s++;
        }
    }
    cout << res << '\n';
}