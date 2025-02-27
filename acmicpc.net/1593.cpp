#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
map<char, pii> m;
int main(){
    int a, b; cin>>a>>b;
    string str; cin>>str;
    for(auto it:str){
        m[it].first++;
    }
    string s; cin>>s;
    for(int i=0; i<a; ++i){
        m[s[i]].second++;
    }
    int distance=0;
    for(auto it:m){
        if(it.second.first!=it.second.second){
            distance++;
        }
    }
    int res=!distance;
    for(int i=a; i<b; ++i){
        char prev = s[i-a];
        char now = s[i];
        if(m[prev].first == m[prev].second){
            distance++;
        }
        else if(m[prev].first == m[prev].second - 1){
            distance--;
        }
        m[prev].second--;
        if(m[now].first == m[now].second){
            distance++;
        }
        else if(m[now].first == m[now].second + 1){
            distance--;
        }
        m[now].second++;

        if(distance==0) res++;
    }
    cout << res << '\n';
}