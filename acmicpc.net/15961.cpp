#include <bits/stdc++.h>
using namespace std;
int cnt[3001];
int p,n;
int total=0;
int N, d, k, c;
int result=0;
bool flag=false;
void f(){
    int res=0;
    res+=total;
    if(flag && cnt[c]==0) res++;
    result = max(result,res);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>d>>k>>c;
    vector<int> v;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        v.push_back(a);
        if(a==c) flag=true;
    }
    for(int i=0; i<N; ++i){
        v.push_back(v[i]);
    }

    for(int i=0; i<k; ++i){
        if(++cnt[v[i]]==1){
            total++;
        }
    }

    for(int i=k; i<v.size()-1; ++i){
        if(++cnt[v[i]]==1){
            total++;
        }

        if(--cnt[v[i-k]]==0){
            total--;
        }

        f();
    }
    
    if(!flag) result++;
    cout << result << '\n';
}