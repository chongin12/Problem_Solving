#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int N, M; cin>>N>>M;
        int a=0, b=0;
        for(int i=0; i<M; ++i){
            int w; cin>>w; a=a*10+w;
        }
        for(int i=0; i<M; ++i){
            int w; cin>>w; b=b*10+w;
        }
        vector<int> v;
        int cnt=0;
        for(int i=0; i<N; ++i){
            int w; cin>>w; v.push_back(w);
        }
        for(int i=0; i<N; ++i){
            int m=0;
            for(int j=0; j<M; ++j){
                m=m*10+v[(i+j)%N];
            }
            if(a<=m && m<=b) cnt++;
        }
        cout << cnt << '\n';
    }
}