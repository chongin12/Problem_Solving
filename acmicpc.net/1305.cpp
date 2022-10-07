#include <bits/stdc++.h>
using namespace std;
int F[1000001];
int main(){
    int L; cin>>L;
    string str; cin>>str;
    F[1]=0;
    for(int i=1, j=0; i<str.size(); ++i){
        while(j>0 && str[i]!=str[j]) j=F[j-1];
        if(str[i]==str[j]) F[i]=++j;
        // cout << "F["<<i<<"]="<<F[i]<<'\n';
    }
    cout <<str.size()-F[str.size()-1]<<'\n';
}