#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,string>;
map<string, int> m;
int main(){
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        string str; cin>>str;
        m[str]=0;
    }
    cin.ignore();
    for(int i=0; i<n; ++i){
        string str;
        getline(cin, str);
        string t="";
        for(auto it:str){
            if(it==' '){
                m[t]++;
                t="";
            }
            else {
                t+=it;
            }
        }
        m[t]++;
    }
    vector<pii> v;
    for(auto it:m){
        v.push_back({-it.second, it.first});
    }
    sort(v.begin(), v.end());
    for(auto it:v){
        cout << it.second << " " << -it.first << '\n';
    }
}