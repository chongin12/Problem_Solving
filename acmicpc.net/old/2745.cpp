#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int B; cin>>str>>B;
    int k=1;
    int res=0;
    for(int i=str.size()-1; i>=0; --i){
        if(str[i]>='0' && str[i]<='9') res+=k*(str[i]-'0');
        else res+=k*(str[i]-'A'+10);
        k*=B;
    }
    cout << res << '\n';

}