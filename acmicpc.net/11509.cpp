#include <bits/stdc++.h>
using namespace std;
int m[1000001];
int main(){
    int N; cin>>N;
    int res=0;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        if(m[a]!=0){
            m[a]-=1;
            if(a!=1) m[a-1]+=1;
        }
        else{
            res++;
            m[a-1]+=1;
        }
    }
    cout << res << '\n';
}