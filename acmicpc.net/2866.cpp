#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int res=0;
int R, C;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>R>>C;
    for(int i=0; i<C; ++i){
        v.push_back("");
    }
    for(int i=0; i<R; ++i){
        string str; cin>>str;
        for(int j=0; j<C; ++j){
            v[j].push_back(str[j]);
        }
    }
    for(int i=0; i<C; ++i){
        reverse(v[i].begin(), v[i].end());
    }
    sort(v.begin(), v.end());
    for(int i=1; i<v.size(); ++i){
        int cnt=0;
        for(int j=0; j<R; ++j, cnt++){
            if(v[i-1][j]!=v[i][j]) break;
        }
        res=max(res,cnt);
    }
    cout << R-1-res << '\n';
}