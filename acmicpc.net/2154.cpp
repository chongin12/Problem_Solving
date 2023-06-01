#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    string str;
    for(int i=1; i<=n; ++i){
        str+=to_string(i);
    }
    cout << str.find(to_string(n))+1 << '\n';
}