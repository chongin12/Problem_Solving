#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    int l=1, r=1;
    int acc=1;
    int res=0;
    while(r<=N && l<=N){
        if(acc==N){
            res++;
            acc+=++r;
            acc-=l++;
        }
        else if(acc<N){
            acc+=++r;
        }
        else{
            acc-=l++;
        }
    }
    cout << res << '\n';
}