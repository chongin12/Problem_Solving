#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    int cnt=0;
    while(T--){
        cout << "Case #"<<++cnt<<": ";
        int N; cin>>N;
        vector<int> v;
        for(int i=0; i<N; ++i){
            int a; cin>>a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        int res=0;
        for(int i=0; i<v.size(); ++i){
            if(v[i]>=res+1) res++;
            else continue;
        }
        cout << res << '\n';
    }
}