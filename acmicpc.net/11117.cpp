#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        string str; cin>>str;
        map<char, int> s;
        for(auto it:str){
            s[it]++;
        }
        int W; cin>>W;
        while(W--){
            string target; cin>>target;
            map<char, int> temp;
            bool flag=true;
            for(auto it:target){
                temp[it]++;
                if(s[it]<temp[it]) flag=false;
            }
            if(flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}