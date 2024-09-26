#include <bits/stdc++.h>
using namespace std;
int res=0;
int A[10001], B[10001], chk[10001], cnt=0;
int main(){
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        cin>>A[i];
    }
    for(int i=1; i<=N; ++i){
        cin>>B[i];
        chk[i] = A[i]==B[i];
        if(chk[i]) cnt++;
    }
    if(cnt==N){
        cout << "1\n";
        return 0;
    }
    for(int last=N; last>1; --last){
        for(int i=1; i<=last-1; ++i){
            if(A[i]>A[i+1]){
                swap(A[i], A[i+1]);
                // chk가 달라지면 cnt도 반영. cnt가 N이면 종료. true 출력.
                if(chk[i] != (A[i]==B[i])){
                    if(chk[i]){
                        chk[i]=0;
                        cnt--;
                    } else {
                        chk[i]=1;
                        cnt++;
                    }
                }
                if(chk[i+1] != (A[i+1]==B[i+1])){
                    if(chk[i+1]){
                        chk[i+1]=0;
                        cnt--;
                    } else {
                        chk[i+1]=1;
                        cnt++;
                    }
                }
                if(cnt==N){
                    cout << "1\n";
                    return 0;
                }
            }
            
            // for(int i=1; i<=N; ++i){
            //     cout << A[i] << " ";
            // }
            // cout << '\n';
            // for(int i=1; i<=N; ++i){
            //     cout << B[i] << " ";
            // }
            // cout << '\n';
            // cout << "cnt : " << cnt << '\n';
        }
    }
    cout << "0\n";
}