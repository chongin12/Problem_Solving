#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int N; cin>>N;
        if(N==0) break;
        vector<int> v;
        vector<int> temp(N);
        for(int i=0; i<N; ++i){
            int a; cin>>a; v.push_back(a);
        }
        for(int i=0; i<6; ++i){
            temp[i]=1;
        }
        do {
            for(int i=0; i<N; ++i){
                if(temp[i]==1) cout << v[i] << ' ';
            }
            cout << '\n';
        } while(prev_permutation(temp.begin(), temp.end()));
        cout << '\n';
    }
}