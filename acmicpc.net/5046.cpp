#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int arr[20];
int res=INF;
int main(){
    int N, B, H, W; cin>>N>>B>>H>>W;
    for(int i=0; i<H; ++i){
        cin>>arr[i];
        for(int j=0; j<W; ++j){
            int a; cin>>a;
            if(a>=N){
                res=min(res, N*arr[i]);
            }
        }
    }
    if(res==INF || res>B) cout << "stay home\n";
    else cout << res << '\n';
}