#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        bool res=false;
        for(int i=2; i<65; ++i){
            int temp=N;
            vector<int> v;
            bool flag=true;
            while(temp) {
                v.push_back(temp%i);
                temp/=i;
            }
            for(int j=0; j<=v.size()/2; ++j){
                if(v[j]!=v[v.size()-1-j]) flag=false;
            }
            if(flag) res=true;
        }
        if(res) cout << "1\n";
        else cout << "0\n";
    }
}