#include <bits/stdc++.h>
using namespace std;
vector<int> getPi(string p){
    int m=(int)p.size(), j=0;
    vector<int> pi(m, 0);
    for(int i=1; i<m; ++i){
        while(j>0 && p[i]!=p[j]){
            j=pi[j-1];
        }
        if(p[i] == p[j]){
            pi[i]=++j;
        }
    }
    return pi;
}
vector<int> kmp(string s, string p){
    vector<int> ans;
    vector<int> pi=getPi(p);
    int n=(int)s.size(), m=p.size(), j=0;
    for(int i=0; i<n; ++i){
        while(j>0 && s[i]!=p[j]){
            j=pi[j-1];
        }
        if(s[i]==p[j]){
            if(j==m-1){
                ans.push_back(i-m+1);
                j=pi[j];
            }
            else{
                j++;
            }
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    string s="", p="";
    for(int i=0; i<360000; ++i){
        s+='0';
        p+='0';
    }
    for(int i=0; i<N; ++i){
        int a; cin>>a; s[a]='1';
    }
    for(int i=0; i<N; ++i){
        int a; cin>>a; p[a]='1';
    }
    s+=s;
    vector<int> v=kmp(s,p);
    if(v.size()>0){
        cout << "possible\n";
    }
    else{
        cout << "impossible\n";
    }
}