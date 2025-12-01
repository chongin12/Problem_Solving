#include <bits/stdc++.h>
using namespace std;
int acc[2002];
int main(){
    string str; cin>>str;
    int N=str.size();
    str=str+str;
    int bcnt=0;
    for(int i=0; i<N; ++i){
        acc[i+1]=acc[i];
        if(str[i]=='b') {
            acc[i+1]++;
            bcnt++;
        }
    }
    for(int i=N; i<N*2; ++i){
        acc[i+1]=acc[i];
        if(str[i]=='b') {
            acc[i+1]++;
        }
    }
    int res=0;
    for(int i=1; i<=N; ++i){
        res=max(res,acc[i+bcnt-1]-acc[i-1]);
    }
    cout << bcnt-res << '\n';
}