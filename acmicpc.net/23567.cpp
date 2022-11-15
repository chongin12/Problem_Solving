#include <bits/stdc++.h>
using namespace std;
int arr[10001];
int arrori[10001], accori;
int res=987654321;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; ++i){
        cin>>v[i];
        arrori[v[i]]++;
        if(arrori[v[i]]==1) accori++;
    }
    int l=0, r=0;
    arr[v[0]]=1;
    arrori[v[0]]--;
    if(arrori[v[0]]==0) accori--;
    int acc=1;
    while(l<n){
        if(acc==k){
            if(accori==k){
                res=min(res,r-l+1);
            }
            arr[v[l]]--;
            if(arr[v[l]]==0) acc--;
            arrori[v[l]]++;
            if(arrori[v[l]]==1) accori++;
            l++;
        }
        else{
            if(r==n-1) break;
            ++r;
            arr[v[r]]++;
            if(arr[v[r]]==1) acc++;
            arrori[v[r]]--;
            if(arrori[v[r]]==0) accori--;
        }
    }
    if(res==987654321) cout << "0\n";
    else cout << res << '\n';
}