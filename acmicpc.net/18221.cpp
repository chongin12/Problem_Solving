#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int main(){
    int N; cin>>N;
    int pi, pj;
    int si, sj;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                si=i;
                sj=j;
            }
            if(arr[i][j]==5){
                pi=i;
                pj=j;
            }
        }
    }
    int cnt=0;
    for(int i=min(pi,si); i<=max(pi,si); ++i){
        for(int j=min(pj,sj); j<=max(pj,sj); ++j){
            if(arr[i][j]==1){
                cnt++;
            }
        }
    }
    if((si-pi)*(si-pi)+(sj-pj)*(sj-pj)>=25 && cnt>=3){
        cout << "1\n";
    }
    else{
        cout << "0\n";
    }
}