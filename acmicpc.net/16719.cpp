#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
void f(int l, int r){
    if(l>r) return;
    int minIdx=l;
    for(int i=l+1; i<=r; ++i){
        if(s[minIdx]>s[i]){
            minIdx=i;
        }
    }
    v.push_back(minIdx);
    f(minIdx+1, r);
    f(l, minIdx-1);
}
int main(){
    cin>>s;
    f(0,s.size()-1);
    vector<int> arr;
    for(auto it:v){
        arr.push_back(it);
        sort(arr.begin(), arr.end());
        for(auto itt:arr){
            cout << s[itt];
        }
        cout << '\n';
    }
}