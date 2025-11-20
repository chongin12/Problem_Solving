#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main(){
    queue<int> q;
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        q.push(i);
    }
    vector<int> v;
    while(!q.empty()){
        int phase = N-q.size()+1;
        for(int i=0; i<phase; ++i){
            q.push(q.front());
            q.pop();
        }
        v.push_back(q.front());
        q.pop();
    }
    int cnt=1;
    for(auto it:v){
        arr[it]=cnt++;
    }
    for(int i=1; i<=N; ++i){
        cout << arr[i] << " ";
    }
    cout << '\n';
}