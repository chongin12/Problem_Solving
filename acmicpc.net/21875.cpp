#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1, s2; cin>>s1>>s2;
    int a=abs(s1[0]-s2[0]), b=abs(s1[1]-s2[1]);
    cout << min(a,b) << " " << max(a,b) << '\n';
}