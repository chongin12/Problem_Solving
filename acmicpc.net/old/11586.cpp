#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    string arr[101];
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }
    int k; cin>>k;
    int is=0,ie=n-1,js=0,je=n-1;
    if(k==2){
        js=n-1,je=0;
    }
    else if(k==3){
        is=n-1,ie=0;
    }
    for(int i=is; is<=ie?i<=ie:i>=ie; is<=ie?++i:--i){
        for(int j=js; js<=je?j<=je:j>=je; js<=je?++j:--j){
            cout << arr[i][j];
        }
        cout << '\n';
    }
}