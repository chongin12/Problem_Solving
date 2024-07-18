#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int a, b, c; cin>>a>>b>>c;
        int k=0;
        if(a>b){
            for(int i=c/a; i>=0; --i){
                int j=(c-a*i)/b;
                if(a*i+b*j==c){
                    cout << i << " " << j << '\n';
                    break;
                }
                if(i==0 || k>10000){
                    cout << "Impossible\n";
                    break;
                }
                ++k;
            }
        }
        else{
            for(int i=c/b; i>=0; --i){
                int j=(c-b*i)/a;
                if(b*i+a*j==c){
                    cout << j << " " << i << '\n';
                    break;
                }
                if(i==0 || k>10000){
                    cout << "Impossible\n";
                    break;
                }
                ++k;
            }
        }
    }
}