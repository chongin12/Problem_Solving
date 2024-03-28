#include <bits/stdc++.h>
using namespace std;
string str; 
int arr[201];
vector<int> stk;
int mask[201];
set<string> s;
void f(int idx){
    if(idx>=str.size()){
        string temp = "";
        for(int i=0; i<str.size(); ++i){
            if(mask[i]) continue;
            temp+=str[i];
        }
        s.insert(temp);
        return;
    }
    if(arr[idx]>idx) {
        f(idx+1);
        mask[idx]=1;
        mask[arr[idx]]=1;
        f(idx+1);
        mask[idx]=0;
        mask[arr[idx]]=0;
    }
    else f(idx+1);
    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    fill(arr, arr+201, -1);
    cin>>str;
    for(int i=0; i<str.size(); ++i){
        if(str[i]=='('){
            stk.push_back(i);
        }
        else if(str[i]==')'){
            int idx = stk.back(); stk.pop_back();
            arr[idx]=i;
            arr[i]=idx;
        }
    }
    f(0);
    for(auto it=s.begin(); it!=s.end(); ++it){
        if(*it == str) continue;
        cout << *it << '\n';
    }
}