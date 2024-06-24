#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> v;
void f(int first, int second) {
    int delta = second - first;
    int last = second;
    string res = to_string(first)+to_string(second);
    v.push_back(stoll(res));
    for(int i=0; i<16; ++i){
        last = last+delta;
        if(last<0 || last>9) {
            break;
        }
        res+=char(last+'0');
        v.push_back(stoll(res));
    }
}
int main(){
    ll N; cin>>N;
    for(int i=1; i<=9; ++i){
        v.push_back(i);
        for(int j=0; j<=9; ++j){
            f(i, j);
        }
    }
    sort(v.begin(), v.end());
    int res=0;
    for(auto it:v){
        if(N<it) break;
        res++;
    }
    cout << res << '\n';
}