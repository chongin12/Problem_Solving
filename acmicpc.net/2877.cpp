#include <bits/stdc++.h>
using namespace std;
int main(){
    int K; cin>>K; K--;
    int t=1;
    int cnt=0; // 길이
    while(1){
        if(K<0) {
            K+=t;
            break;
        }
        t<<=1;
        cnt++;
        K-=t;
    }
    //cout << "길이 : " << cnt << ", K : " << K << '\n';
    string binaryString = std::bitset<32>(K).to_string();
    for(int i=32-cnt; i<32; ++i){
        cout << (binaryString[i] == '0' ? '4':'7');
    }
    cout << '\n';
}
