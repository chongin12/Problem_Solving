#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int J, N; cin>>J>>N;
        vector<int> v;
        for(int i=0; i<N; ++i){
            int r, c; cin>>r>>c;
            v.push_back(r*c);
        }
        sort(v.begin(), v.end(), greater());
        int cnt=0;
        for(auto it:v){
            J-=it;
            cnt++;
            if(J<=0) break;
        }
        cout << cnt << '\n';
    }
}