#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    while(1){
        ll nx, ny; ll w;
        ll res=0;
        long double temp;
        cin>>nx>>ny>>temp;
        if(nx==0 && ny==0) break;
        w=temp*10000000;
        vector<ll> v;
        for(int i=0; i<nx; ++i){
            cin>>temp;
            v.push_back(temp*10000000);
        }
        sort(v.begin(), v.end());
        ll prev=0;
        for(auto it:v){
            // cout << it-w/2 << " ~ " << it+w/2 << '\n';
            if(it-w/2<=prev){
                prev=it+w/2;
            }
            else{
                break;
            }
        }
        if(prev>=75*10000000){
            res++;
        }
        v.clear();
        prev=0;
        
        for(int i=0; i<ny; ++i){
            cin>>temp;
            v.push_back(temp*10000000);
        }
        sort(v.begin(), v.end());
        for(auto it:v){
            if(it-w/2<=prev){
                prev=it+w/2;
            }
            else{
                break;
            }
        }
        if(prev>=100*10000000){
            res++;
        }
        if(res==2) cout << "YES\n";
        else cout << "NO\n";
    }
}