#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    if(N==0) {
        cout << "0\n";
        return 0;
    }
    string res="";
    while(N!=1){
        int temp = N/-2;
        if(N<0 && N%2!=0){
            temp++;
        }
        int spare = N-(-2)*temp;
        // cout << N << " / -2 = " << temp << " ... " << spare << '\n';
        res+='0'+spare;
        N=temp;
    }
    res+='1';
    reverse(res.begin(), res.end());
    cout << res << '\n';
}