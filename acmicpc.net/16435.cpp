#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    int N, L; cin>>N>>L;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(auto it:v){
        if(it<=L) L++;
        else break;
    }
    cout << L << '\n';
}