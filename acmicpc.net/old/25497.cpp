#include <bits/stdc++.h>
using namespace std;
int arr[10];
int L,S;
int main(){
    int N; cin>>N;
    string str; cin>>str;
    int cnt=0;
    for(int i=0; i<N; ++i){
        if(str[i]>='1' && str[i]<='9'){
            cnt++;
        }
        else if(str[i]=='L'){
            L++;
        }
        else if(str[i]=='S'){
            S++;
        }
        else if(str[i]=='R'){
            if(L==0) break;
            L--;
            cnt++;
        }
        else{
            if(S==0) break;
            S--;
            cnt++;
        }
    }
    cout << cnt << '\n';
}