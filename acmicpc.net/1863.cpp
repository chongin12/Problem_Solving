#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    vector<int> v;
    int cnt=0;
    for(int i=0; i<N; ++i){
        int a,b; cin>>a>>b;
        while(!v.empty() && v.back()>b){
            cnt++;
            // cout << "found : " << v.back() << '\n';
            v.pop_back();
        }
        if(b!=0) {
            if(v.empty() || v.back() != b){
                v.push_back(b);
            }
        }
    }
    cnt+=v.size();
    cout << cnt << '\n';
}