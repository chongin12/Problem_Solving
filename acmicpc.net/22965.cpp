#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    int prev=-1;
    int first=-1;
    int w=0;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        if(i!=0){
            if(prev>a) w++;
        }
        else {
            first=a;
        }
        prev=a;
    }
    if(w==1 && prev>first) w++;
    if(w>1) cout << "3\n";
    else if(w==1) cout << "2\n";
    else cout << "1\n";
}