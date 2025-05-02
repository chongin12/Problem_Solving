#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, K; cin>>N>>K;
    string str; cin>>str;
    int h=0, v=0;
    for(int i=0; i<min(K,2000); ++i){
        for(auto it:str){
            if(it=='U') v-=1;
            if(it=='D') v+=1;
            if(it=='L') h-=1;
            if(it=='R') h+=1;

            if(v==0 && h==0) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
}