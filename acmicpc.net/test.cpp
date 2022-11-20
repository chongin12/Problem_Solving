#include <iostream>
using namespace std;
int dp[1000];
int arr[1000];
int main(){
    int N; cin >> N;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }

    int res=-1;

    for(int i=0; i<N; ++i){
        dp[i] = max(dp[i], 1);

        for(int j=i+1; j<N; ++j){
            if(arr[i] < arr[j]) {
                dp[i] = max(dp[j], dp[i]+1);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << '\n';
}