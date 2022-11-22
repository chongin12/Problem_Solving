#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int M;
vector<int> t;
int prv=-1; // 가장 마지막에 뺀 원소
void f(int cur, int idx) {
    if(cur==M){
        for(auto it:t) cout << it << " ";
        cout << '\n';
        return;
    }
    for(int i=idx; i<v.size(); ++i){
        if(v[i]==prv) continue;
        t.push_back(v[i]);
        f(cur+1, i+1);
        prv=t.back();
        t.pop_back();
    }
}
int main(){
    int N; cin>>N>>M; v.resize(N);
    for(int i=0; i<N; ++i){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    f(0,0);
}