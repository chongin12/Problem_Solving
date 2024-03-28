#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    int idx=0;
    for(int i=1; i<s.size(); ++i){
        if(s[idx]>=s[i]) idx=i;
    }
    string res="";
    res+=s[idx];
    string temp="";
    int k=idx;
    while(k>0){
        int newIdx=k-1;
        for(int i=k-1; i>=0; --i){
            if(s[i]<s[newIdx]){
                newIdx=i;
            }
        }
        for(int i=k-1; i>newIdx; --i){
            temp=s[i]+temp;
        }
        res+=s[newIdx];
        k=newIdx;
    }
    res+=temp;
    for(int i=idx+1; i<s.size(); ++i){
        res+=s[i];
    }
    cout << res << '\n';
}