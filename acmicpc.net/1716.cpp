#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        int n, k; cin>>n>>k;
        if(n==-1 && k==-1) break;
        vector<int> v;
        for(int i=0; i<n+1; ++i){
            int a; cin>>a; v.push_back(a);
        }
        for(int i=v.size()-1; i>=0; --i){
            if(i<k) break;
            v[i-k]+=-v[i];
            v[i]=0;
        }
        vector<int> res;
        bool flag=false;
        for(int i=v.size()-1; i>=0; --i){
            if(v[i]!=0) flag=true;
            if(flag){
                res.push_back(v[i]);
            }
        }
        if(!flag) res.push_back(0);
        for(int i=res.size()-1; i>=0; --i){
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
}