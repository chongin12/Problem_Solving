#include <bits/stdc++.h>
using namespace std;
vector<int> v(1001);
void init(){
    for(int i=0; i<1001; ++i) v[i]=0;
}
string str;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        init();
        int N; cin>>N;
        if(N==0) break;
        cin>>str;
        int ptr=0;
        int lo=0, hi=0;
        int loOrHi=0;
        while(ptr<=str.size()){
            if(ptr==str.size() || str[ptr]==','){
                if(hi==0) {if(lo>0 && lo<=N) v[lo]=1;}
                else if(lo<=hi) {
                    for(int i=lo; i<=min(hi,N); ++i) v[i]=1;
                }
                loOrHi=0;
                lo=0, hi=0;
                ptr++;
                continue;
            }
            if(str[ptr]=='-'){
                loOrHi=1;
                ptr++;
                continue;
            }
            if(loOrHi==0) lo=lo*10+str[ptr]-'0';
            else hi=hi*10+str[ptr]-'0';
            ptr++;
        }
        int cnt=0;
        for(int i=1; i<=N; ++i){
            if(v[i]) cnt++;
        }
        cout << cnt << '\n';
    }
}