#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        cout << "Case #" << t << endl;
        int N; cin>>N;
        string str; cin>>str;
        int prev=-1;
        int cnt=0;
        int res=0;
        for(int i=0; i<str.size(); ++i){
            if(str[i]=='B'){
                cnt++;
            }
            else {
                if(prev==-1) {
                    prev=i;
                    cnt=0;
                }
                else {
                    res+=max(0, 2-cnt);
                    cnt=0;
                    prev=i;
                }
            }
        }
        cout << res << endl;
    }
}