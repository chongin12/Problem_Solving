#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    string str; cin>>str;
    int res=0;
    while(N--){
        string k; cin>>k;
        for(int i=0; i<k.size(); ++i){
            bool goal=false;
            if(k[i]==str[0]){
                for(int j=1; i+j*(str.size()-1)<k.size(); ++j){
                    bool flag=true;
                    for(int w=1; w<str.size(); ++w){
                        if(k[i+j*w]!=str[w]) {
                            flag=false;
                            break;
                        }
                    }
                    if(flag) {
                        goal=true;
                        break;
                    }
                }
            }
            if(goal) {
                res++;
                break;
            }
        }

    }
    cout << res << '\n';
}