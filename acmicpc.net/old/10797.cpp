#include <iostream>
using namespace std;

int main(){
    int n, cnt=0;
    cin >> n;
    for(int i=0; i<5; ++i){
        int t;
        cin >> t;
        if(t%10 == n%10){
            cnt++;
        }
    }
    cout << cnt;
}