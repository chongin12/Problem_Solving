#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        int cnt=0;
        int p=0;
        bool flag=true;
        for(int i=0; i<n; ++i){
            int a; cin>>a;
            if(i==0) p=a;
            cnt+=a;
        }
        if(n%2==1) cout << "Mike\n";
        else{
            if(p%2==1) 
            if(cnt%2==0){
                cout << "Joe\n";
            }
            else{
                cout << "Mike\n";
            }
        }
        
    }
}