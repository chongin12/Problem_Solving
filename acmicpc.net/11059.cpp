#include <bits/stdc++.h>
using namespace std;
int psum[1002];
int main(){
    string s; cin>>s;
    int N=s.size();
    psum[0]=0;
    for(int i=1; i<=N; ++i){
        psum[i]=psum[i-1]+s[i-1]-'0';
    }
    for(int i=N/2; i>0; --i){
        for(int j=0; j+i+i<=N; ++j){
            if(psum[j+i]-psum[j] == psum[j+i+i]-psum[j+i]){
                cout << i+i << '\n';
                return 0;
            }
        }
    }
}