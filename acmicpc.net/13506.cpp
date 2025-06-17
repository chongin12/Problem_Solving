#include <bits/stdc++.h>
using namespace std;
const int MN=1e6+1;
int Z[MN*2];
int L=0, R=0;
int main(){
    string S; cin>>S;
    int N=S.size();
    S=S+"$"+S;
    S.pop_back();
    for(int i=1; i<S.size(); ++i){
        if(R<i){
            L=i;
            R=i-1;
            for(int j=0; j+i<S.size(); ++j){
                if(S[j]==S[i+j]){
                    R=i+j;
                }
                else {
                    break;
                }
            }
            Z[i]=R-L+1;
        }
        else {
            int k=i-L;
            if(i+Z[k]-1<R){
                Z[i]=Z[k];
            }
            else {
                L=i;
                for(int j=R-i+1; i+j<S.size(); ++j){
                    if(S[j]==S[i+j]){
                        R=i+j;
                    }
                    else {
                        break;
                    }
                }
                Z[i]=R-L+1;
            }
        }
    }
    int resM=0;
    priority_queue<int> pq;
    for(int i=1; i<N; ++i){
        // cout << S[i] << " -> " << "Z["<<i<<"]="<<Z[i]<<'\n';
        if(i+Z[i]==N) {
            pq.push(Z[i]); // prefix, suffix 같은거
        }
    }
    for(int i=N+2; i<S.size(); ++i){
        // cout << S[i] << " -> " << "Z["<<i<<"]="<<Z[i]<<'\n';
        resM=max(resM,Z[i]);
    }
    int res=0;
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(cur>resM) continue;
        for(int i=0; i<cur; ++i){
            cout << S[i];
        }
        cout << '\n';
        return 0;
    }
    cout << "-1\n";
}