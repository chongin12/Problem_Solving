#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main(){
    int N; cin>>N;
    int res=0;
    for(int i=0; i<N; ++i){
        cin>>arr[i]; res^=arr[i];
    }
    if(res==0) {
        cout << "0\n";
        return 0;
    }
    int cnt=0;
    for(int i=0; i<N; ++i){
        for(int j=arr[i]-1; j>=0; --j){
            if((res^arr[i]^j)==0) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << '\n';
}