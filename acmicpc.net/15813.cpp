#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    string str; cin>>str;
    int res=0;
    for(auto it:str){
        res+=it-'A'+1;
    }
    cout << res << '\n';
}