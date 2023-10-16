#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int main(){
    int N; cin>>N;
    int res=0;
    string resstr="";
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        m[str]+=1;
        if(res<m[str]){
            res=m[str];
            resstr=str;
        }
        else if(res==m[str]){
            resstr=min(resstr, str);
        }
    }
    cout << resstr << '\n';

}