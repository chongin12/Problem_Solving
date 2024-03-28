#include <bits/stdc++.h>
using namespace std;
int arr[5001];
int f(int x){
    string a = to_string(x);
    bool flag=true;
    for(int i=1; i<a.size(); ++i){
        for(int j=0; j<i; ++j){
            if(!flag) break;
            if(a[i]==a[j]) flag=false;
        }
        if(!flag) break;
    }
    return flag;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=1; i<5001; ++i){
        if(f(i)) arr[i]=1;
    }
    while(1){
        int a,b;
        cin >> a >> b;
        if(cin.eof()) break;
        int r=0;
        for(int i=a; i<=b; ++i){
            r+=arr[i];
        }
        cout << r << '\n';
    }
}