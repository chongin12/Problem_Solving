#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int res=987654321;
int arr[20];
void f(int k, int cnt, int acc){
    // cout << "k : " << k << ", cnt : " << cnt << ", acc : " << acc << '\n';
    if(cnt==20){
        if(k==0) res=min(res,acc);
        return;
    }
    if(cnt==0) {
        f((k^arr[0])^(arr[1]), cnt+1, acc+1);
    }
    else if(cnt==19){
        f((k^arr[18])^arr[19], cnt+1, acc+1);
    }
    else {
        f(((k^arr[cnt+1])^arr[cnt])^arr[cnt-1], cnt+1, acc+1);
    }
    f(k, cnt+1, acc);
}
int main(){
    for(int i=0; i<20; ++i){
        int a; cin>>a;
        v.push_back(a);
    }
    arr[0]=1;
    for(int i=1; i<20; ++i){
        arr[i]=arr[i-1]*2;
    }
    int k=1;
    int temp=0;
    for(int i=19; i>=0; --i){
        if(v[i]==1) temp+=k;
        k*=2;
    }
    f(temp, 0, 0);
    cout << res << '\n';
}