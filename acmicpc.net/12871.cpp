#include <bits/stdc++.h>
using namespace std;
int main(){
    string str1, str2; cin>>str1>>str2;
    for(int i=0; i<2501; ++i){
        if(str1[i%str1.size()]!=str2[i%str2.size()]){
            cout << "0\n";
            return 0;
        }
    }
    cout << "1\n";
}