#include <bits/stdc++.h>
using namespace std;
vector<char> v;
int L, C;
string res;
void f(int n, int k, bool hasConsonant, int vowel){
    if(k==L) { if(hasConsonant && vowel>=2) cout << res << '\n'; }
    else{
        for(int i=n+1; i<C; ++i){
            res.push_back(v[i]);
            if(v[i]=='a' || v[i]=='e' || v[i]=='i' || v[i]=='o' || v[i]=='u')
                f(i,k+1,true,vowel);
            else f(i,k+1,hasConsonant, vowel+1);
            res.pop_back();
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>L>>C;
    for(int i=0; i<C; ++i){
        char a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    f(-1,0,0,0);
}