#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    int cnt=0;
    for(int i=1; i<N; ++i){
        int temp = i;
        while(temp>0){
            if(temp%100==50) { cnt++; break; }
            temp/=10;
        }
        cnt++;
    }
    cout << cnt + 1 << '\n';
}