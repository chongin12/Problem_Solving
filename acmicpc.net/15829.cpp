#include <iostream>
#include <string>
#define m 1234567891
#define r 31
using namespace std;
using ll = long long int;
ll f(int i){
    if(i==0) return 1;
    ll cnt=1;
    for(int t=0; t<i; ++t){
        cnt = cnt * r % m;
        if(cnt==0) cnt=m;// 0이 되면 안됨. 곱하기에 0 있으면 안됨.
    }
    return cnt;
}
int main(){
    int L; cin >> L;
    string str; cin >> str;
    ll res=0;
    for(int i=0; i<L; ++i){
        res += (str[i]-'a'+1) * f(i) % m;
    }
    
    cout << res % m << '\n';
}