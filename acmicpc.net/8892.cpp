#include <bits/stdc++.h>
using namespace std;
bool isPel(string a, string b){
    string temp = a+b;
    for(int i=0; i<temp.size()/2; ++i){
        if(temp[i]!=temp[temp.size()-1-i]) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int K; cin>>K;
        vector<string> v;
        bool flag=false;
        for(int i=0; i<K; ++i){
            string s; cin>>s;
            if(flag) continue;
            v.push_back(s);
            for(int j=0; j<i; ++j){
                if(isPel(v[j],s)){
                    cout << v[j]+s << '\n';
                    flag=true;
                    break;
                }
                else if(isPel(s,v[j])){
                    cout << s+v[j] << '\n';
                    flag=true;
                    break;
                }
            }
        }
        if(!flag) cout << "0\n";
    }
}