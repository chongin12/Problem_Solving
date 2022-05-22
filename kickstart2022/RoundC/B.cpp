#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        int N, X, Y; cin>>N>>X>>Y;
        int total=(1+N)*N/2;
        bool flag=true;
        if(total%(X+Y)) {
            cout << "Case #"<<t<<": IMPOSSIBLE\n";
            continue;
        }
        total=(total/(X+Y))*X;
        vector<int> v;
        int now=N;
        for(int i=N; i>=1; --i){
            if(total>=i){
                v.push_back(i);
                total-=i;
            }
        }
        if(total!=0){
            cout << "Case #"<<t<<": IMPOSSIBLE\n";
            continue;
        }
        else{
            cout << "Case #"<<t<<": POSSIBLE\n";
        }
        cout << v.size() << '\n';
        for(auto it:v) cout << it << ' ';
        cout << '\n';
    }
}