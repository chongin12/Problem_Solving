#include <bits/stdc++.h>
using namespace std;
using pds=pair<double,string>;
int main(){
    while(1){
        int N; cin>>N;
        vector<pair<double, string>> v;
        if(N==0) break;
        double k=0.0;
        for(int i=0; i<N; ++i){
            string s; cin>>s;
            double h; cin>>h;
            k=max(h,k);
            v.push_back({h,s});
        }
        for(auto it:v){
            if(it.first==k) cout << it.second << ' ';
        }
        cout << '\n';
    }

}