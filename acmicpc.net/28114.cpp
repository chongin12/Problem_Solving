#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v1;
    vector<pair<int,char>> v2;
    for(int i=0; i<3; ++i){
        int a,b;
        string c;
        cin>>a>>b>>c;
        v1.push_back(b%100);
        v2.push_back({-a, c[0]});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(auto it:v1)cout << it;
    cout << '\n';
    for(auto it:v2) cout << it.second;
    cout << '\n';
}