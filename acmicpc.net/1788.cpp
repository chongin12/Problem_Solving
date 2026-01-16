#include <bits/stdc++.h>
using namespace std;
const int MN=1000000000;
int main(){
    int N; cin>>N;
    int a=0, b=1;
    if(N>0){
        for(int i=1; i<N; ++i){
            int c=(a+b)%MN;
            a=b;
            b=c;
        }
        cout << "1\n";
        cout << b << '\n';
    }
    else if(N<0){
        for(int i=0; i>N; --i){
            int c=(b-a)%(-MN);
            b=a;
            a=c;
        }
        if(a<0) cout << "-1\n";
        else cout << "1\n";
        cout << abs(a) << '\n';
    }
    else{
        cout << "0\n";
        cout << "0\n";
    }
}