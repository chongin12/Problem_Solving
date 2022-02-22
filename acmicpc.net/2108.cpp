#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<int> v;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    double k=0;
    for(int i=0; i<N; ++i){
        k+=(double)v[i];
    }
    cout << floor((k/(double)N)+0.5) << '\n';
    cout << v[N/2] << '\n';
    int mc=1;
    int rc=0;
    vector<int> res;
    for(int i=1; i<N; ++i){
        if(v[i]==v[i-1]) mc++;
        else{
            if(rc<mc) {
                rc=mc;
                res.clear();
                res.push_back(v[i-1]);
            }
            else if(rc==mc){
                res.push_back(v[i-1]);
            }
            mc=1;
        }
    }
    if(rc<mc) {
        rc=mc;
        res.clear();
        res.push_back(v[N-1]);
    }
    else if(rc==mc){
        res.push_back(v[N-1]);
    }
    if(res.size()!=1){
        cout << res[1] << '\n';
    }
    else{
        cout << res[0] << '\n';
    }
    cout << v[N-1]-v[0] << '\n';
}