#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        v.push_back(a);
    }
    int res=2;
    int acc=2;
    for(int i=2; i<N; ++i){
        if(v[i-2]>=v[i-1] && v[i-1]>=v[i]){
            res=max(res,acc);
            acc=2;
        }
        else if(v[i-2]<=v[i-1] && v[i-1]<=v[i]){
            res=max(res,acc);
            acc=2;
        }
        else{
            acc+=1;
        }
    }
    cout << max(res,acc) << '\n';
}