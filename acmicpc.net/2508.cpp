#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        vector<string> v;
        int r, c; cin>>r>>c;
        for(int i=0; i<r; ++i){
            string str; cin>>str;
            v.push_back(str);
        }
        int res=0;
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(v[i][j]=='o'){
                    if(j>0 && j<c-1 && v[i][j-1]=='>' && v[i][j+1]=='<'){
                        res++;
                    }
                    else if(i>0 && i<r-1 && v[i-1][j]=='v' && v[i+1][j]=='^') res++;
                }
            }
        }
        cout << res << '\n';
    }
}