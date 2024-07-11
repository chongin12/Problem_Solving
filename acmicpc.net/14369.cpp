#include <bits/stdc++.h>
using namespace std;
map<string, string> m;
const string NUM[]={
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE"
};
void f(string s, string v, int prev, int phase){
    string temp=s;
    sort(temp.begin(), temp.end());
    m[temp]=v;
    if(phase==6) return;
    for(int i=prev; i<=9; ++i){
        f(s+NUM[i], v+to_string(i), i, phase+1);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    f("", "", 0, 0);
    for(int t=1; t<=T; ++t){
        string str; cin>>str;
        sort(str.begin(), str.end());
        cout << "Case #"<<t<<": " << m[str] << '\n';
    }
}