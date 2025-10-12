#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        vector<int> v;
        int temp[11];
        for(int i=0; i<N; ++i){
            int c; cin>>c;
            if(c%2) c++;
            v.push_back(c);
        }
        int res=0;
        while(1){
            bool flag=true;
            for(int i=0; i<N; ++i){
                if(v[i]!=v[0]) flag=false;
            }
            if(flag) {
                cout << res << '\n';
                break;
            }
            res++;
            memset(temp, 0, sizeof temp);
            for(int i=0; i<N; ++i){
                temp[i]=v[i]/2;
                v[i]/=2;
            }
            for(int i=0; i<N; ++i){
                v[(i+1)%N]+=temp[i];
            }
            for(int i=0; i<N; ++i){
                if(v[i]%2) v[i]+=1;
            }
        }
    }
}