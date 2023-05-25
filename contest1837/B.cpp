#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        string str; cin>>str;
        int res=0;
        int a=0, b=0;
        int now=0;
        char prev='.';
        int strick=0;
        for(auto it:str){
            if(prev != it){
                if(prev=='<'){
                    a=max(a,strick);
                }
                else if(prev=='>'){
                    b=max(b,strick);
                }
                strick = 0;
            }
            strick++;
            prev=it;
        }
        if(prev=='<'){
            a=max(a,strick);
        }
        else if(prev=='>'){
            b=max(b,strick);
        }
        cout << max(a,b)+1 << '\n';
    }
}

// 12345 12345
// 123123