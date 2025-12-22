#include <bits/stdc++.h>
using namespace std;
int main(){
    int asdf=0;
    while(1){
        int N; cin>>N;
        if(N==0) return 0;
        int t=N;
        int cnt2=0, cnt5=0;
        for(int i=2; N>=i; i*=2){
            cnt2+=t/i;
        }
        t=N;
        for(int i=5; N>=i; i*=5){
            cnt5+=t/i;
        }
        // cout << cnt2 << " " << cnt5 << '\n';

        cout << "Case #"<<++asdf<<": "<<min(cnt2,cnt5) << '\n';
    }
}