#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll X1, X2, Y1, Y2; cin>>X1>>Y1>>X2>>Y2; X2--; Y2--;
    ll res=0;
    for(ll i=Y1; i<=Y2; ++i){
        if(i%2){
            res+=max<ll>(0,min(i,X2+1)-X1);
        }
    }
    for(ll i=X1; i<=X2; ++i){
        if(i%2){
            res+=max<ll>(0,min(i,Y2+1)-Y1);
        }
    }
    for(ll i=X1; i<=X2; ++i){
        if(i%2==0) continue;
        if(Y1<=i && i<=Y2) res++;
    }
    cout << res << '\n';
}
/*
X1=0 Y1=0 X2=1 Y2=0
기본적으로 홀수에만 있음.
3번째 행을 포함하면 3번째 열까지 겹치는 부분 개수 세기
3번째 열을 포함하면 2번째 행까지 겹치는 부분 개수 세기.

*/