#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M, K; cin>>N>>M>>K;
    int res=0;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        int cnt=0;
        for(auto it:str){
            if(it=='0') cnt++;
            else {
                res+=max(0, cnt-K+1);
                cnt=0;
            }
        }
        res+=max(0, cnt-K+1);
    }
    cout << res << '\n';
}