#include <bits/stdc++.h>
using namespace std;
int arr[]={6,2,5,5,4,5,6,3,7,6};
int main(){
    int N; cin>>N;
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            for(int k=0; k<10; ++k){
                for(int w=0; w<10; ++w){
                    int result=i*10+j+k*10+w;
                    if(result>99) break;
                    if(arr[i]+arr[j]+arr[k]+arr[w]+4+arr[result/10]+arr[result%10]==N){
                        cout << i << j << "+" << k << w << "=" << result/10 << result%10 << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << "impossible\n";
}