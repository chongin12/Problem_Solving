#include <bits/stdc++.h>
using namespace std;
int main(){
    int A[]={3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
    string str1,str2; cin>>str1>>str2;
    vector<int> v;
    for(int i=0; i<str1.size(); ++i){
        v.push_back(A[str1[i]-'A']);
        v.push_back(A[str2[i]-'A']);
    }
    while(v.size()>2){
        for(int i=0; i<v.size()-1; ++i){
            v[i]=v[i]+v[i+1];
            v[i]%=10;
        }
        v.pop_back();
    }
    cout << v[0] << v[1] << '\n';
}