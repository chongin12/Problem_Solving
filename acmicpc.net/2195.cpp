#include <bits/stdc++.h>
using namespace std;
string temp;
int main(){
    string S,P; cin>>S>>P;
    int res=0;
    int clear=0;
    while(1){
        int maxCnt=0;
        for(int offset=0; offset<S.size(); ++offset){
            int i;
            for(i=0; i<min(offset+(int)S.size(), (int)P.size()-clear); ++i){
                if(S[offset+i]!=P[i+clear]){
                    break;
                }
            }
            maxCnt=max(maxCnt, i);
        }
        // cout << "maxCnt="<<maxCnt << '\n';
        // cout << "clear="<<clear<<", P.size()="<<P.size() << '\n';
        clear+=maxCnt;
        res++;
        if(clear==P.size()) break;
    }
    cout << res << '\n';
}