#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        int N,M; cin>>N>>M;
        if(N==0) break;
        vector<pii> v;
        for(int i=0; i<N; ++i){
            int a, b, c, d; cin>>a>>b>>c>>d;
            v.push_back({c,c+d});
        }
        for(int i=0; i<M; ++i){
            int mv=0;
            int a, b; cin>>a>>b;
            for(auto it:v){
                if(!(a+b<=it.first || it.second<=a)) mv++;
            }
            cout << mv << '\n';
        }
    }
}