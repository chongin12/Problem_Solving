#include <bits/stdc++.h>
using namespace std;
vector<string> v;
vector<int> arr;
int N, M;
int res=0;
string target="";
string Union(string s1, string s2) {
    for(int i=0; i<M; ++i){
        if(s2[i]=='Y'){
            s1[i]='Y';
        }
    }
    return s1;
}
void f(int phase, int prev) {
    if(phase==0){
        string s="";
        for(int i=0; i<M; ++i){s+="N";}
        
        for(auto it:arr){
            s=Union(s,v[it]);
        }
        bool flag=true;
        for(int i=0; i<M; ++i){
            if(target[i]=='Y' && s[i]=='N'){
                flag=false;
                break;
            }
        }
        if(flag) res=1;
        return;
    }
    for(int i=prev+1; i<N; ++i){
        arr.push_back(i);
        f(phase-1, i);
        arr.pop_back();
    }
}
int main(){
    cin>>N>>M;
    for(int i=0; i<M; ++i){target+="N";}
    for(int i=0; i<N; ++i){
        string str1, str2; cin>>str1>>str2;
        v.push_back(str2);
        target=Union(target,str2);
    }
    bool flag=true;
    for(auto it:target){
        if(it=='Y') flag=false;
    }
    if(flag) {
        cout << "-1\n";
        return 0;
    }
    for(int i=1; i<=N; ++i){
        f(i, -1);
        if(res) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}