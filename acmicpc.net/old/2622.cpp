#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    int cnt=0;
    for(int k=(N-1)/2; k>=1; --k){
        int t1=k, t2=N-2*k;
        if(t2>k) break;
        if(k>=t1+t2) break;
        while(t2<=t1){
            if(t2>=1) cnt++;
            t2++;
            t1--;
        }
    }
    cout << cnt << '\n';
}