#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int P; cin>>P;
    while(P--){
        int a; cin>>a; cout << a << " ";
        vector<int> v;
        int cnt=0;
        for(int i=0; i<20; ++i){
            cin>>a;
            v.push_back(a);
            for(int i=v.size()-1; i>=1; --i){
                if(v[i]<v[i-1]) {
                    swap(v[i], v[i-1]);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}