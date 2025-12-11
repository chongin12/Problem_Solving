#include <bits/stdc++.h>
using namespace std;
int main(){
    int N1, N2; cin>>N1>>N2;
    string s1, s2; cin>>s1>>s2;
    reverse(s2.begin(), s2.end());
    int T; cin>>T;
    int cnt1=-N1*2+2;
    int cnt2=1-T*2;
    string res="";
    while(!s1.empty() && !s2.empty()){
        if(cnt1<cnt2){
            res+=s1.back(); s1.pop_back();
            cnt1+=2;
        }
        else{
            res+=s2.back(); s2.pop_back();
            cnt2+=2;
        }
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    cout << res+s1+s2 << '\n';
}