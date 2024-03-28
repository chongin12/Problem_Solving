#include <bits/stdc++.h>
using namespace std;
int res=0;
void f(int x){
    if(x==1) return;
    res+=(x/2)*(x-x/2);
    f(x/2);
    f(x-x/2);
}
int main(){
    int N; cin>>N;
    f(N);
    cout << res << '\n';
}