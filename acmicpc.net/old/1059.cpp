#include <iostream>
using namespace std;
int arr[1001];
int main(){
    int L; cin >> L;
    int a;
    for(int i=0; i<L; ++i){
        cin >> a;
        arr[a] = 1;
    }

    int n; cin >> n;
    int left=1, right=1000;
    for(int i=n; i>0; --i) {
        if(arr[i]==1) {
            left=i+1;
            break;
        }
    }
    for(int i=n; i<=1000; ++i){
        if(arr[i]==1) {
            right=i-1;
            break;
        }
    }
    int count = 0;
    for(int i=left; i<n; ++i){
        count += right-n+1;
    }
    count += right-n;
    if(count == -1) cout << 0 << '\n';
    else cout << count << '\n';
}