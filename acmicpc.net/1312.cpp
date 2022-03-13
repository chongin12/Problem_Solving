#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,n; cin>>a>>b>>n;
    int r=a/b;
    a=a%b*10;
    while(n--){
        r=a/b;
        a=a%b*10;
    }
    cout << r << '\n';
}