#include <bits/stdc++.h>
using namespace std;
int arr[41];
int main(){
    vector<int> v;
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        arr[a]++;
    }
    bool isReadingTwo=1;
    int cnt=0;
    int res=1;
    for(int i=0; i<41; ++i){
        if(arr[i]>2){
            cout << "0\n";
            return 0;
        }
        else {
            if(isReadingTwo){
                if(arr[i]==2){
                    cnt+=2;
                    res*=2;
                }
                else if(arr[i]==1){
                    isReadingTwo = 0;
                    cnt++;
                }
                else if(arr[i]==0){
                    break;
                }
            }
            else {
                if(arr[i]==2){
                    cout << "0\n";
                    return 0;
                }
                else if(arr[i]==0){
                    break;
                }
                else {
                    cnt++;
                }
            }
        }
    }
    if(cnt!=N) {
        cout << "0\n";
        return 0;
    }
    if(isReadingTwo==0) res*=2;
    cout << res << '\n';
}