#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> v;
vector<int> acc;
void f(int cur){
    if(cur==M){
        for(auto it:acc){
            cout << it << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=0; i<v.size(); ++i){
        acc.push_back(v[i]);
        f(cur+1);
        acc.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N>>M;
    v.resize(N);
    for(int i=0; i<N; ++i){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()),v.end());
    f(0);
}