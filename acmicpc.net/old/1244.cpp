#include <bits/stdc++.h>
using  namespace std;
int arr[105];
int main(){
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        cin>>arr[i];
    }
    int k; cin>>k;
    for(int i=0; i<k; ++i){
        int a, b ;cin>>a>>b;
        if(a==1){
            for(int j=1; j*b<=N; j++){
                arr[j*b]=!arr[j*b];
            }
        } else {
            for(int j=0; b-j>0 && b+j<=N; ++j){
                if(arr[b-j]==arr[b+j]){
                    if(j==0) arr[b]=!arr[b];
                    else{
                        arr[b-j]=!arr[b-j];
                        arr[b+j]=!arr[b+j];
                    }
                }
                else break;
            }
        }
    }
    for(int i=1; i<=N; ++i){
        cout << arr[i] << " ";
        if(i%20==0) cout << '\n';
    }
    cout << '\n';
}