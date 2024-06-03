#include <bits/stdc++.h>
using namespace std;
int chk[1001]={};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    map<string, int> m;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        m[str]=i;
    }
    int cnt=0;
    int res=0;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        while(chk[cnt]) cnt++;
        if(m[str]!=cnt) {
            res++;
            chk[m[str]]=1;
        }
        else {
            cnt++;
        }
    }
    cout << res << '\n';
}