#include <bits/stdc++.h>
using namespace std;
int arr[48];
int s[48];
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    for(int i=0; i<N; ++i){
        cin>>s[i];
    }
    for(int i=0; i<122000; ++i){
        bool flag=true;
        for(int j=0; j<N; ++j){
            if(arr[j]!=j%3) flag=false;
        }
        if(flag){
            cout << i << '\n';
            return 0;
        }
        int nxt[48]={};
        for(int j=0; j<N; ++j){
            nxt[s[j]]=arr[j];
        }
        for(int j=0; j<N; ++j){
            arr[j]=nxt[j];
        }
    }
    cout << "-1\n";
}