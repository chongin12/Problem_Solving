#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int resnum=0, residx=0;
    for(int i=0; i<n; ++i){
        vector<int> v(5);
        for(int j=0; j<5; ++j){
            cin>>v[j];
        }
        for(int j=0; j<5; ++j){
            for(int k=j+1; k<5; ++k){
                for(int w=k+1; w<5; ++w){
                    int t = (v[j]+v[k]+v[w])%10;
                    if(t>=resnum){
                        residx=i;
                        resnum=t;
                    }
                }
            }
        }
    }
    cout << residx+1 << '\n';
}