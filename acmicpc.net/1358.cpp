#include <bits/stdc++.h>
using namespace std;
int dist(int a, int b, int A, int B){
    return (a-A)*(a-A)+(b-B)*(b-B);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int W, H, X, Y, P; cin>>W>>H>>X>>Y>>P;
    int r=0;
    for(int i=0; i<P; ++i){
        int a, b; cin>>a>>b;
        if(a<=X){
            if(dist(X, Y+H/2, a, b)<=(H/2)*(H/2)) r++;
        }
        else if(a<=X+W){
            if(b>=Y && b<=Y+H) r++;
        }
        else {
            if(dist(X+W, Y+H/2, a, b)<=(H/2)*(H/2)) r++;
        }
    }
    cout << r<< '\n';
}