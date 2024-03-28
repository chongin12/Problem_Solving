#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        int a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    if(v.size()==0) {
        cout << "0\n";
    }
    else {
        int k = floor((double) n * 15.0 / 100.0 + 0.5);
        int sum=0;
        for(int i=k; i<n-k; ++i){
            sum+=v[i];
        }
        int avg = floor((double)sum / (n-2*k) + 0.5);
        cout << avg << '\n';
    }
}