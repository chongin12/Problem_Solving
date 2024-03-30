#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll s, t;
string temp = "";
string res = "//////////////////////////////";
bool flag = false;

void f(int x){
    if(x>t) return;
    if(x==t) {
        flag=true;
        if(temp.size()<res.size()) res=temp;
        else res = min(res,temp);
        return;
    }
    if(temp.size()>=res.size()) return;
    // 1. 제곱
    if(x!=1 && x<=32000) {
        temp+="*";
        f(x*x);
        temp.pop_back();
    }

    // 2. *2
    temp+="+";
    f(x+x);
    temp.pop_back();
}

int main(){
    cin>>s>>t;
    if(s==t){
        cout << "0\n";
        return 0;
    }
    if(t==1){
        cout << "/\n";
        return 0;
    }
    if(t==2){
        if(s==1) cout << "+\n";
        else cout << "/+\n";
        return 0;
    }
    f(s);
    if(s==1){
        temp="";
    }
    else {
        temp="/";
    }
    f(1);

    if(flag){
        cout << res << '\n';
        return 0;
    }
    cout << "-1\n";

}