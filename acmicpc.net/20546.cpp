#include <bits/stdc++.h>
using namespace std;
int main(){
    int k; cin>>k;
    int A=k, B=k;
    int aCnt=0, bCnt=0;
    int upStreak=0, downStreak=0;
    int prev=-1;
    int n;
    for(int i=0; i<14; ++i){
        cin>>n;
        if(A>=n){
            aCnt+=A/n;
            A%=n;
        }
        if(i){
            if(prev<n){
                upStreak++;
                downStreak=0;
            }
            else if(prev>n){
                upStreak=0;
                downStreak++;
            }
            else {
                upStreak=0;
                downStreak=0;
            }
        }
        if(upStreak>=3){
            B+=bCnt*n;
            bCnt=0;
        }
        if(downStreak>=3){
            bCnt+=B/n;
            B%=n;
        }
        prev=n;
    }
    A+=aCnt*n;
    B+=bCnt*n;
    if(A>B){
        cout << "BNP\n";
    }
    else if(A<B){
        cout << "TIMING\n";
    }
    else{
        cout << "SAMESAME\n";
    }
}