#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int> G[11];
int main(){
    ll A, B, C; cin>>A>>B>>C;
    for(ll x=1; x<=10; ++x){
        for(ll y=1; y<=10; ++y){
            if(A*x+B*y==C){
                G[x].push_back(y);
            }
        }
    }
    for(int i=1; i<=10; ++i){
        if(G[i].size()==0){
            cout << "0\n";
        }
        else{
            for(auto it:G[i]){
                cout << it << " ";
            }
            cout << '\n';
        }
    }
}