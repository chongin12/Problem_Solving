#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    int idx=0;
    for(int i=1; ; ++i){
        string t=to_string(i);
        for(auto it:t){
            if(str[idx]==it && (++idx)>=str.size()){
                cout << i << '\n';
                return 0;
            }
        }
    }
}