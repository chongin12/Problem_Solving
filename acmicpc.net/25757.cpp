#include <bits/stdc++.h>
using namespace std;
set<string> s;
int main(){
    int N; cin>>N;
    string str; cin>>str;
    for(int i=0; i<N; ++i){
        string a; cin>>a;
        s.insert(a);
    }
    if(str=="Y") cout << s.size() << '\n';
    else if(str=="F") cout << s.size()/2 << '\n';
    else cout << s.size()/3 << '\n';
}