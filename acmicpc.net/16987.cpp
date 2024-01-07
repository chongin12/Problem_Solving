#include <bits/stdc++.h>
using namespace std;
int str[10];
int arr[10];
int N;
int res=0;
void f(int phase) {
    if(phase==N){
        int sum=0;
        for(int i=0; i<N; ++i){
            if(arr[i]<=0) sum++;
        }
        res=max(res,sum);
        return;
    }
    if(arr[phase]<=0){
        f(phase+1);
        return;
    }
    bool flag=true;
    for(int i=0; i<N; ++i){
        if(i==phase) continue;
        if(arr[i]<=0) continue;
        arr[i]-=str[phase];
        arr[phase]-=str[i];
        f(phase+1);
        arr[i]+=str[phase];
        arr[phase]+=str[i];
        flag=false;
    }
    if(flag){
        f(phase+1);
    }
}
int main(){
    cin>>N;
    for(int i=0; i<N; ++i){
        int a, b; cin>>a>>b;
        arr[i]=a;
        str[i]=b;
    }
    f(0);
    cout << res << '\n';

}