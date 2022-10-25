#include <bits/stdc++.h>
using namespace std;
int S[1000001];
int F[1000001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        cin>>S[N-i-1];
    }
    for(int i=1, j=0; i<N; ++i){
        while(j>0 && S[j]!=S[i]) j=F[j-1];
        if(S[j]==S[i]) F[i]=++j;
        cout << "F["<<i<<"]="<<F[i]<<'\n';
    }
    int k=0,p=N;
    for(int i=1, j=0; i<N; ++i){
        // k와 p 찾기
        while(j>0 && S[j]!=S[i]) j=F[j-1];
        if(S[j]==S[i]) F[i]=++j;
        int tk=N-i-1, tp=F[i];
        cout << "tk : " << tk << ", tp : " << tp << '\n';
        if(tp>0 && k+p>tk+tp){
            k=tk;
            p=tp;
        }
        else if(tp>0 && k+p==tk+tp && p>tp){
            k=tk;
            p=tp;
        }
    }
    cout << k << " " << p << '\n';
}