#include <bits/stdc++.h>
using namespace std;
int dr[8]={-2,-1,0,1,2,1,0,-1};
int dc[8]={0,-1,-2,-1,0,1,2,1};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; cin>>str;
    string res[5];
    for(int i=0; i<5; ++i){
        for(int j=0; j<4*str.size()+1; ++j){
            res[i].push_back('.');
        }
    }
    for(int i=0; i<str.size(); ++i){
        res[2][4*i+2]=str[i];
        if((i+1)%3==0) continue;
        for(int j=0; j<8; ++j){
            res[2+dr[j]][4*i+2+dc[j]]='#';
        }
    }
    for(int i=2; i<str.size(); i+=3){
        for(int j=0; j<8; ++j){
            res[2+dr[j]][4*i+2+dc[j]]='*';
        }
    }
    for(int i=0; i<5; ++i){
        for(int j=0; j<4*str.size()+1; ++j){
            cout << res[i][j];
        }
        cout << '\n';
    }
}