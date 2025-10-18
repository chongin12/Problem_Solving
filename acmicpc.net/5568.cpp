#include <bits/stdc++.h>
using namespace std;
vector<string> v;
set<string> s;
int main(){
    int N, K; cin>>N>>K;
    for(int i=0; i<N; ++i){
        string a; cin>>a; v.push_back(a);
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(i==j) continue;
            if(K>=3){
                for(int k=0; k<N; ++k){
                    if(i==k || j==k) continue;
                    if(K>=4){
                        for(int w=0; w<N; ++w){
                            if(i==w || j==w || k==w) continue;
                            s.insert(v[i]+v[j]+v[k]+v[w]);
                        }
                    }
                    else{
                        s.insert(v[i]+v[j]+v[k]);
                    }
                }
            }
            else {
                s.insert(v[i]+v[j]);
            }
        }
    }
    cout << s.size() << '\n';
}