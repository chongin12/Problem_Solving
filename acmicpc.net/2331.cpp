#include <bits/stdc++.h>
using namespace std;
int visited[1000001];
int pows[10];
int A, P;
int f(int x){
    int ret=0;
    while(x>0){
        ret+=pows[x%10];
        x/=10;
    }
    return ret;
}
int main(){
    cin>>A>>P;
    for(int i=1; i<10; ++i){
        pows[i]=pow(i, P);
    }
    int cnt=1;
    while(1){
        if(visited[A]){
            cout << visited[A]-1 << '\n';
            break;
        }
        visited[A]=cnt++;
        A=f(A);
    }
}