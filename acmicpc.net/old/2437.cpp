#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    vector<int> v(N);
    for(int i=0; i<N; ++i){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int k=1;
    if(v[0]!=1) {
        cout << 1 << '\n';
        return 0;
    }
    else{
        for(int i=1; i<v.size(); ++i){
            if(v[i]<=k+1){
                k+=v[i];
            }
            else{
                cout << k+1 << '\n';
                return 0;
            }
        }
    }
    cout << k+1 << '\n';
}