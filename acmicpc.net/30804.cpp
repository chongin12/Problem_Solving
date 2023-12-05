#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    int res=0;
    for(int i=1; i<=9; ++i){
        for(int j=i+1; j<=9; ++j){
            int cnt=0;
            for(int k=0; k<N; ++k){
                if(v[k]==i || v[k]==j){
                    cnt++;
                    res=max(res,cnt);
                }
                else {
                    cnt=0;
                }
            }
        }
    }
    cout << res << '\n';
}