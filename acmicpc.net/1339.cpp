#include <bits/stdc++.h>
using namespace std;
int arr[10];
int isFilled[11];
vector<string> v;
int res=0;
void calc() {
    int ret=0;
    for(auto it:v){
        int temp=0;
        for(auto c:it){
            temp=temp*10+arr[c-'A'];
        }
        ret+=temp;
    }
    res=max(res,ret);
}
void f(int phase){
    if(phase==10){
        calc();
        return;
    }
    for(int i=1; i<=10; ++i){
        if(isFilled[i]) continue;
        isFilled[i]=1;
        arr[phase]=i-1;
        f(phase+1);
        isFilled[i]=0;
    }
}
int main(){
    int N; cin>>N;
    set<char> ref;
    vector<string> temp;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        for(auto it:str) ref.insert(it);
        temp.push_back(str);
    }
    map<char,char> m;
    char ch='A';
    for(auto it = ref.begin(); it!=ref.end(); ++it){
        m[*it]=ch;
        ch++;
    }
    for(auto it:temp){
        string newStr="";
        for(auto c:it){
            newStr.push_back(m[c]);
        }
        v.push_back(newStr);
    }
    f(0);
    cout << res << '\n';
}