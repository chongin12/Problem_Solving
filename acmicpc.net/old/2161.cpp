#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    vector<int> v;
    queue<int> q;
    for(int i=0; i<N; ++i){
        q.push(i+1);
    }
    while(!q.empty()){
        v.push_back(q.front());
        q.pop();
        q.push(q.front());
        q.pop();
    }
    for(auto it:v){
        cout << it << " ";
    }
    cout << '\n';
}