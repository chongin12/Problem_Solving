#include <bits/stdc++.h>
using namespace std;
int N;
vector<string> ans;
bool solve(string s) {
    string temp="+";
    for(int i=0; i<N; ++i){
        temp+=i+'1';
        if(s[i]!=' ') temp+=s[i];
    }
    int res=0;
    string acc="";
    for(int i=temp.size()-1; i>=0; --i){
        if(temp[i]=='+') {
            res+=stoi(acc);
            acc="";
        }
        else if(temp[i]=='-') {
            res-=stoi(acc);
            acc="";
        }
        else{
            acc=temp[i]+acc;
        }
    }
    if(res==0) return true;
    else return false;
}
void f(int phase, string s){
    if(phase==N-1){
        if(solve(s)) ans.push_back(s);
        return;
    }
    f(phase+1, s+"+");
    f(phase+1, s+"-");
    f(phase+1, s+" ");
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        cin>>N;
        f(0, "");
        sort(ans.begin(), ans.end());
        for(auto it:ans){
            for(int i=0; i<N-1; ++i){
                cout << i+1;
                cout << it[i];
            }
            cout << N << '\n';
        }
        cout << '\n';
        ans.clear();
    }
}