#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B; cin>>A>>B;
    int N; cin>>N;
    int res=abs(A-B);
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        res=min(res,abs(B-a)+1);
    }
    cout << res << '\n';
}