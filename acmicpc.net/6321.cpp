#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        cout << "String #" << i+1 << '\n';
        string str; cin>>str;
        for(int i=0; i<str.size(); ++i){
            if(str[i]=='Z') cout << 'A';
            else cout << (char)(str[i]+1);
        }
        cout << "\n\n";
    }
}