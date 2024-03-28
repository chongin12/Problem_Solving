#include <bits/stdc++.h>
using namespace std;
int a[] = {100, 50, 20, 10, 5, 2, 1};
int main(){
    int N; cin>>N;
    int r1=0, r2=0;
    int cnt=0;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        if(i==0) r1+=a;
        else if(r1<=r2) r1+=a;
        else r2+=a;
    }
    int r=abs(r1-r2);
    for(int i=0; i<7; ++i){
        cnt+=r/a[i];
        r%=a[i];
    }
    cout << cnt << '\n';
}