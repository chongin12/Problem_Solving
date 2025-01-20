#include <bits/stdc++.h>
using namespace std;
int main(){
    string S, T; cin>>S>>T;
    while(S.size() != T.size()){
        if(T.back()=='A'){
            T.pop_back();
        }
        else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }
    cout << (S==T?1:0) << '\n';
}
