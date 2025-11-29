#include <bits/stdc++.h>
using namespace std;
int res[5];
int main(){
    int R, C; cin>>R>>C;
    vector<string> v;
    for(int i=0; i<R; ++i){
        string str; cin>>str;
        v.push_back(str);
    }
    for(int i=0; i<R-1; ++i){
        for(int j=0; j<C-1; ++j){
            int cnt=0;
            bool flag=false;
            for(int k=0; k<2; ++k){
                for(int w=0; w<2; ++w){
                    int cx=i+k;
                    int cy=j+w;
                    if(v[cx][cy]=='#') flag=true;
                    if(v[cx][cy]=='X') cnt++;
                }
            }
            if(!flag){
                res[cnt]++;
            }
        }
    }
    for(int i=0; i<5; ++i){
        cout << res[i] << '\n';
    }
}