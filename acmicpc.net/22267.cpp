#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
void f(){
    while(pq.size()>1){
        int a=pq.top(); pq.pop();
        int b=pq.top(); pq.pop();
        if(a==b){
            pq.push(a+1);
        } else {
            pq.push(a);
            pq.push(b);
            break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; pq.push(a);
    }
    if(pq.size()==1){
        cout << "N\n";
        return 0;
    }
    f();
    pq.pop();
    f();
    
    if(pq.size()<=1) cout << "Y\n";
    else cout << "N\n";
}