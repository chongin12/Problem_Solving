#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    int cnt=0;
    while(T--){
        cout << "Case #" << ++cnt << ":\n";
        int R, C; cin>>R>>C;
        for(int i=0; i<R*2+1; ++i){
            for(int j=0; j<C*2+1; ++j){
                if((i==0 && j==0)||(i==0 && j==1)||(i==1 && j==0)){
                    cout << ".";
                }
                else if(i%2==1 && j%2==1){
                    cout << ".";
                }
                else if(i%2==0 && j%2==0){
                    cout << "+";
                }
                else if(i%2==1 && j%2==0){
                    cout << "|";
                }
                else{
                    cout << "-";
                }
            }
            cout << '\n';
        }
    }
}