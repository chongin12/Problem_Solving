#include <bits/stdc++.h>
using namespace std;
int arr[41][41];
int main(){
    int R, C; cin>>R>>C;
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            cin>>arr[i][j];
        }
    }
    int res=0;
    int T; cin>>T;
    for(int i=0; i<R-2; ++i){
        for(int j=0; j<C-2; ++j){
            vector<int> v;
            for(int k=0; k<3; ++k){
                for(int w=0; w<3; ++w){
                    int x=i+k;
                    int y=j+w;
                    v.push_back(arr[x][y]);
                }
            }
            sort(v.begin(), v.end());
            if(T<=v[4]) res++;
        }
    }
    cout << res << '\n';
}