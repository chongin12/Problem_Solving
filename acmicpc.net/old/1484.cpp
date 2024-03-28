#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> res;
    for(int i=1; i<=n; ++i){
        if(n%i!=0) continue;
        int j=n/i;
        if(i>j) break;
        if((j-i)%2!=0) continue;
        int m=(j-i)/2;
        if(m==0) continue;
        res.push_back(j-m);
    }
    reverse(res.begin(), res.end());
    for(auto it:res) cout << it << '\n';
    if(res.size()==0) cout << "-1\n";
}