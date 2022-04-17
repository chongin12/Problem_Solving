#include <bits/stdc++.h>
using namespace std;
int f(int x){
    int ret=0;
    while(x){
        ret+=x%10;
        x/=10;
    }
    return ret;
}
int main(){
    string str; cin>>str;
    int N=0;
    for(auto it:str) N+=it-'0';
    int cnt=0;
    if(str.size()!=1) cnt+=1;
    while(N>=10){
        N=f(N);
        cnt++;
    }
    cout << cnt << '\n';
    if(N!=0 && N%3==0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}