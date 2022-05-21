#include <bits/stdc++.h>
using namespace std;
int main(){
    int l,r,k; cin>>l>>r>>k;
    if(k==2){
        cout << max(0, r-max(3,l)+1) << '\n';
    }
    else if(k==3){
        cout << max(0, r/3-max(5,l-1)/3) << '\n';
    }
    else if(k==4){
        int t=0;
        if(l<=12 && r>=12) t=1;
        cout << max(0, r/2-max(9,l-1)/2-t) << '\n';
    }
    else{
        cout << max(0, r/5-max(14,l-1)/5) << '\n';
    }
}