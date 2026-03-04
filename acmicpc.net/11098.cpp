#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int p; cin>>p;
        vector<pair<int,string>> v;
        for(int i=0; i<p; ++i){
            int a; string str; cin>>a>>str;
            v.push_back({a,str});
        }
        sort(v.begin(), v.end());
        cout << v.back().second << '\n';
    }
}