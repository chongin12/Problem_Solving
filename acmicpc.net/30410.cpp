#include <bits/stdc++.h>
using namespace std;
int res=0;
void calcMax(int num){ // 2의 개수를 받아서 계산
    int i;
    for(i=1;i<=num;i<<=1);
    // cout << "num : " << num << ", i : " << i << '\n';
    res=max(res,i);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    int acc2=0; // 쌓인 2의 개수
    int phase=0; // phase : 1 or 2
    int acc1=0;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        if(a==1){
            acc1++;
        }
        else {
            if(phase!=2) {
                if(acc1%2){
                    calcMax(acc2+acc1/2);
                    acc2=acc1/2;
                    acc1=0;
                }
                else{
                    acc2+=acc1/2;
                    acc1=0;
                }
            }
            acc2++;
        }
        phase=a;
    }
    calcMax(acc2+acc1/2);
    cout << res << '\n';
}