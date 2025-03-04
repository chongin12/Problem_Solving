#include <bits/stdc++.h>
using namespace std;
int main(){
    int k; cin>>k;
    int n; cin>>n;
    string str; cin>>str;
    vector<string> v;
    for(int i=0; i<n; ++i){
        string str; cin>>str;
        v.push_back(str);
    }
    vector<int> res1, res2;
    for(int i=0; i<k; ++i){
        res1.push_back(i);
        res2.push_back(str[i]-'A');
    }
    for(int i=0; i<n; ++i){
        if(v[i][0]=='?') break;
        for(int j=0; j<k-1; ++j){
            if(v[i][j]=='-'){
                swap(res1[j], res1[j+1]);
            }
        }
    }
    for(int i=n-1; i>=0; --i){
        if(v[i][0]=='?') break;
        for(int j=0; j<k-1; ++j){
            if(v[i][j]=='-'){
                swap(res2[j], res2[j+1]);
            }
        }
    }
    string ret="";
    for(int i=0; i<k-1; ++i){
        if(res1[i]==res2[i]) {
            ret+="*";
            continue;
        }
        if(res1[i]==res2[i+1]) {
            swap(res2[i], res2[i+1]);
            ret+="-";
        }
        else {
            ret="";
            for(int j=0; j<k-1; ++j){
                ret+="x";
            }
            cout << ret << '\n';
            return 0;
        }
    }
    cout << ret << '\n';
}