#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    int t=0;
    while(t<T){
        ++t;
        int N, B; cin>>N>>B;
        vector<int> v;
        for(int i=0; i<N; ++i){
            int a; cin>>a; v.push_back(a);
        }
        sort(v.begin(), v.end());
        int i=0;
        while(i<N && B>=v[i]) B-=v[i++];
        cout << "Case #"<<t<<": "<<i<<'\n';
    }
}