#include <bits/stdc++.h>
using namespace std;
int sum[10001];
int main(){
    int k=2;
    sum[1]=1;
    for(int i=2; i<1001; ){
        for(int j=0; j<k; ++j){
            sum[i]=sum[i-1]+k;
            ++i;
        }
        ++k;
    }
    int a,b; cin>>a>>b;
    cout << sum[b]-sum[a-1] << '\n';
}