#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int w=sqrt(n);
    int h;
    if(n%w==0) h=n/w;
    else h=n/w+1;
    w=max(1,w-1);
    h=max(1,h-1);
    cout << (w+h)*2 << '\n';
}