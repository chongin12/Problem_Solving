#include <bits/stdc++.h>
using namespace std;
int isErased[10001];
vector<int> prime;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=2; i*i<10001; ++i){
        if(isErased[i]) continue;
        for(int j=i*i; j<10001; j+=i){
            isErased[j]=1;
        }
    }
    for(int i=2; i<10001; ++i){
        if(!isErased[i]) prime.push_back(i);
    }
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        for(int j=0; prime[j]*prime[j]<=a; ++j) {
            while(a%prime[j]==0){
                cout << prime[j] << " ";
                a/=prime[j];
            }
        }
        if(a!=1) cout << a;
        cout << '\n';
    }
}