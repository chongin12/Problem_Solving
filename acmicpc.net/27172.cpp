#include <bits/stdc++.h>
using namespace std;
int cnt[1000001];
int chk[1000001];
vector<int> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        chk[a]=1;
        v.push_back(a);
    }
    for(int i=1; i<=1000000; ++i){
        if(chk[i]){
            for(int j=i+i; j<=1000000; j+=i){
                if(chk[j]) {
                    cnt[i]++;
                    cnt[j]--;
                }
            }
        }
    }
    for(auto it:v){
        cout << cnt[it] << " ";
    }
    cout << '\n';
}