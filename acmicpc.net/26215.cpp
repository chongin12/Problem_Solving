#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    priority_queue<int> pq;
    for(int i=0; i<N; ++i){
        int a; cin>>a; pq.push(a);
    }
    int res=0;
    while(pq.size()>=2){
        int a=pq.top(); pq.pop();
        int b=pq.top(); pq.pop();
        res+=min(a,b);
        if(max(a,b)-min(a,b)) pq.push(max(a,b)-min(a,b));
    }
    if(pq.size()==1) res+=pq.top();
    if(res>1440) cout << "-1\n";
    else cout << res << '\n';
}