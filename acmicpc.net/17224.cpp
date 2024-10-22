#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, L, K; cin>>N>>L>>K;
    int c1=0, c2=0;
    for(int i=1; i<=N; ++i){
        int s1, s2; cin>>s1>>s2;
        if(s2<=L) c2++;
        else if(s1<=L) c1++;
    }
    if(c2>=K) cout << 140*K << '\n';
    else if(c1>=K-c2) cout << 140*c2+100*(K-c2) << '\n';
    else cout << 140*c2+100*c1 << '\n';
}