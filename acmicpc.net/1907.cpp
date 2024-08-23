#include <bits/stdc++.h>
using namespace std;
struct Node {
    int c=0, h=0, o=0;

    Node operator*(int a){
        return Node({c*a, h*a, o*a});
    }
    Node operator+(Node b){
        return Node({c+b.c, h+b.h, o+b.o});
    }
    bool operator==(Node b){
        return c==b.c && h==b.h && o==b.o;
    }
};
int main(){
    string a, b, c;
    Node A, B, C;
    string s; cin>>s;
    int idx=0;
    for(;idx<s.size(); ++idx){
        if(s[idx]=='+') break;
        if(s[idx]>='0' && s[idx]<='9'){
            for(int i=0; i<(s[idx]-'0')-1; ++i){
                a+=a.back();
            }
        }
        else {
            a+=s[idx];
        }
    }
    idx++;
    for(;idx<s.size(); ++idx){
        if(s[idx]=='=') break;
        if(s[idx]>='0' && s[idx]<='9'){
            for(int i=0; i<(s[idx]-'0')-1; ++i){
                b+=b.back();
            }
        }
        else {
            b+=s[idx];
        }
    }
    idx++;
    for(;idx<s.size(); ++idx){
        if(s[idx]>='0' && s[idx]<='9'){
            for(int i=0; i<(s[idx]-'0')-1; ++i){
                c+=c.back();
            }
        }
        else {
            c+=s[idx];
        }
    }

    for(auto it:a){
        if(it=='C') A.c++;
        if(it=='H') A.h++;
        if(it=='O') A.o++;
    }
    for(auto it:b){
        if(it=='C') B.c++;
        if(it=='H') B.h++;
        if(it=='O') B.o++;
    }
    for(auto it:c){
        if(it=='C') C.c++;
        if(it=='H') C.h++;
        if(it=='O') C.o++;
    }

    for(int i=1; i<=10; ++i){
        for(int j=1; j<=10; ++j){
            for(int k=1; k<=10; ++k){
                if(A*i+B*j==C*k){
                    cout << i << " " << j << " " << k << '\n';
                    return 0;
                }
            }
        }
    }
}