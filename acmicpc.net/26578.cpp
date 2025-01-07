#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int r, c; cin>>r>>c;
        vector<string> v;
        int res=0;
        for(int i=0; i<r; ++i){
            string str; cin>>str;
            v.push_back(str);
        }
        for(int i=0; i<r; ++i){
            for(int j=0; j<c-3; ++j){
                if(v[i][j]=='w' && v[i][j+1]=='o' && v[i][j+2]=='r' && v[i][j+3]=='d'){
                    res++;
                }
                if(v[i][j]=='d' && v[i][j+1]=='r' && v[i][j+2]=='o' && v[i][j+3]=='w'){
                    res++;
                }
            }
        }
        for(int i=0; i<r-3; ++i){
            for(int j=0; j<c; ++j){
                if(v[i][j]=='w' && v[i+1][j]=='o' && v[i+2][j]=='r' && v[i+3][j]=='d'){
                    res++;
                }
                if(v[i][j]=='d' && v[i+1][j]=='r' && v[i+2][j]=='o' && v[i+3][j]=='w'){
                    res++;
                }
            }
        }
        for(int i=0; i<r-3; ++i){
            for(int j=0; j<c-3; ++j){
                if(v[i][j]=='w' && v[i+1][j+1]=='o' && v[i+2][j+2]=='r' && v[i+3][j+3]=='d'){
                    res++;
                }
                if(v[i][j]=='d' && v[i+1][j+1]=='r' && v[i+2][j+2]=='o' && v[i+3][j+3]=='w'){
                    res++;
                }
            }
        }
        for(int i=0; i<r-3; ++i){
            for(int j=3; j<c; ++j){
                if(v[i][j]=='w' && v[i+1][j-1]=='o' && v[i+2][j-2]=='r' && v[i+3][j-3]=='d'){
                    res++;
                }
                if(v[i][j]=='d' && v[i+1][j-1]=='r' && v[i+2][j-2]=='o' && v[i+3][j-3]=='w'){
                    res++;
                }
            }
        }
        cout << res << '\n';
    }
}