#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string str;
string trim(string a){
    string ret=string();
    int flag=false;
    for(int i=0; i<a.size(); ++i){
        if(flag) ret+=a[i];
        else{
            if(a[i]!='0'){
                flag=true;
                ret+=a[i];
            }
        }
    }
    return ret;
}
int moreThan(string a, string b){ // a>=b, 둘 다 trim된 상태여야 함.
    if(a.size()>b.size()){
        return 1;
    }
    if(a.size()<b.size()){
        return 0;
    }
    return a>=b;
}
int f(int idx, string s) { // idx까지 봤을 때 마지막을 s보다 작게 자르기 가능여부
    if(idx<0) return 1;
    if(idx==0){
        if(moreThan(string()+str[0], s)) return 0;
        else return 1;
    }
    for(int i=idx; i>=0; --i){
        string end = string();
        for(int j=i; j<=idx; ++j){
            end+=str[j];
        }
        end=trim(end);
        if(moreThan(end, s)) break;
        if(f(i-1, end)) return 1;
    }
    return 0;
}
int main(){
    cin>>str;
    for(int i=str.size()-1; i>=0; --i){
        string end = string();
        for(int j=i; j<str.size(); ++j){
            end+=str[j];
        }
        end=trim(end);
        if(f(i-1, end)) {
            if(end.size()==0) cout << "0\n";
            else cout << end << '\n';
            break;
        }
    }
}