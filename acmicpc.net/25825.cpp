#include <bits/stdc++.h>
using namespace std;
int arr[12][12];
int main(){
    vector<int> v = {0,1,2,3,4,5};
    for(int i=0; i<12; ++i){
        for(int j=0; j<12; ++j){
            cin>>arr[i][j];
        }
    }
    int res=987654321;
    do {
        for(int i=0; i<(1<<6); ++i){
            vector<int> order;
            for(int j=0; j<6; ++j){
                if(i&(1<<j)){
                    order.push_back(v[j]*2+0);
                    order.push_back(v[j]*2+1);
                }
                else {
                    order.push_back(v[j]*2+1);
                    order.push_back(v[j]*2+0);
                }
            }
            int cnt=0;
            for(int j=1; j<12; ++j){
                cnt+=arr[order[j-1]][order[j]];
            }
            res=min(res,cnt);
        }
    } while(next_permutation(v.begin(), v.end()));
    cout << res << '\n';
}