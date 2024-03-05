#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<pair<int,int>> v;
    for(int i=0; i<N; ++i){
        int a, b; cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), [](pii a, pii b){
        return a.first<b.first;
    });
    priority_queue<int, vector<int>, greater<int>> pq;
    int res=0;
    for(auto it:v){
        int a=it.first, b=it.second;
        while(!pq.empty()){
            if(pq.top()<=a) pq.pop();
            else{
                break;
            }
        }
        pq.push(b);
        res=max(res,(int)pq.size());
    }
    cout << res << '\n';
}