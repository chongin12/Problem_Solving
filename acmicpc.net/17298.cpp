#include <iostream>
using namespace std;
int arr[1000001];
bool chk[1000001];
int dp[1000001]; // 다음 오큰수의 위치 저장
int f(int pos, int comp) { // 현재위치,비교할 수 입력(기준), 위치 반환
    if(dp[pos]==-1) return -1;
    else if(arr[dp[pos]]>comp) return dp[pos];
    else return f(dp[pos], comp);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
        if(i) chk[i-1]=arr[i]>arr[i-1];
    }
    dp[N]=-1;
    dp[N-1]=-1;
    for(int i=N-1; i>=0; --i){
        if(!chk[i]) {
            dp[i]=f(i+1, arr[i]);
        } else {
            dp[i]=i+1;
        }
        //cout << "dp[" << i << "] = " << dp[i] << '\n';
    }
    for(int i=0; i<N; ++i){

        if(dp[i]==-1) cout << -1 << " ";
        else cout << arr[dp[i]] << " ";
    }
    cout << '\n';
}