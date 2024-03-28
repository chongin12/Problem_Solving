#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    vector<int> v(N);
    for(int i=0; i<N; ++i){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int toCheck=v[0];
    for(int i=1; i<N; ++i){
        if(i>toCheck) break;
        if(v[i]>v[i-1]) toCheck+=v[i]-v[i-1];
    }
    cout << toCheck+1 << '\n';
}