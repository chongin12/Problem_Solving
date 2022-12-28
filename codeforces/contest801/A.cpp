#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int arr[41][41]={};
        int n,m; cin>>n>>m;
        int mi=0, mj=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin>>arr[i][j];
                if(arr[i][j]>arr[mi][mj]){
                    mi=i;
                    mj=j;
                }
            }
        }
        cout << max(n-mi,mi+1)*max(m-mj,mj+1) << '\n';
    }
}