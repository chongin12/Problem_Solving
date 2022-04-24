#include <bits/stdc++.h>
using namespace std;
string f(int a){
    string ret="";
    for(int i=0; i<8-a; ++i){
        ret+="0";
    }
    for(int i=8-a; i<8; ++i){
        ret+="1";
    }
    return ret;
}
int main(){
    int T; scanf("%d", &T);
    int N=0;
    bool flag=false;
    while(T--){
        printf("00000000\n");
        scanf("%d", &N);
        while(1){
            string str=f(N);
            printf("%s\n", str.c_str());
            fflush(stdout);
            scanf("%d", &N);
            if(N==0) break;
            if(N==-1){
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
}