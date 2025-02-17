#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    int cur=0;
    int res=0;
    for(auto it:str){
        if(it=='('){
            cur+=1;
        }
        else if(it==')'){
            cur-=1;
        }
        else if(it=='{'){
            cur+=2;
        }
        else if(it=='}'){
            cur-=2;
        }
        else if(it=='['){
            cur+=3;
        }
        else if(it==']'){
            cur-=3;
        }
        else {
            res=max(res,cur);
        }
    }
    cout << res << '\n';
}