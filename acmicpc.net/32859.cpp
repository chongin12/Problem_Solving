#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
    int N, M; cin>>N>>M;
    int S; cin>>S;
    vector<pii> v;
    vector<int> res;
    for(int i=0; i<M; ++i){
        int a, b; cin>>a>>b;
        v.push_back({a,b});
    }
    for(int i=1; i<=N; ++i){
        int cnt=0;
        for(auto it:v){
            if(cnt && it.second==0){
                cnt++;
            }
            if(it.first==i) {
                if(it.second==0) break;
                cnt=1;
            }
            if(cnt>S){
                res.push_back(i);
                break;
            }
        }
    }
    if(res.size()==0){
        cout << "-1\n";
    } else {
        for(auto it:res){
            cout << it << '\n';
        }
    }
}