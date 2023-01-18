#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int R,C; cin>>R>>C;
    vector<pair<int,int>> v;
    vector<int> res(R);
    for(int i=0; i<R; ++i){
        string str; cin>>str;
        for(int j=C-2; j>=1; --j){
            if(str[j]!='.'){
                v.push_back({C-j,str[j]-'1'});
                break;
            }
        }
    }
    sort(v.begin(), v.end());
    int rank=1;
    res[v[0].second]=rank;
    for(int i=1; i<9; ++i){
        if(v[i].first!=v[i-1].first){
            rank++;
        }
        res[v[i].second]=rank;
    }
    for(int i=0; i<9; ++i){
        cout << res[i] << '\n';
    }
}