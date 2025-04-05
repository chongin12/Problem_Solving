#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int N, L;
bool f(vector<int> v){
    bool flag1=true;
    int chk[101]={0,};
    for(int j=1; j<N; ++j){
        if(v[j]!=v[j-1]){
            if(v[j]-1==v[j-1]){
                bool goal=true;
                for(int k=L; k>=1; --k){
                    if(j-k<0 || chk[j-k] || v[j-k]!=v[j]-1){
                        goal=false;
                        break;
                    }
                }
                if(!goal) {
                    flag1=false;
                    break;
                }
            }
            else if(v[j]+1==v[j-1]){
                bool goal=true;
                for(int k=L-1; k>=0; --k){
                    if(j+k>=N || v[j+k]!=v[j]){
                        goal=false;
                        break;
                    }
                    chk[j+k]=1;
                }
                if(!goal) {
                    flag1=false;
                    break;
                }
            }
            else {
                flag1=false;
                break;
            }
            
        }
    }
    return flag1;
}
int main(){
    cin>>N>>L;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin >> arr[i][j];
        }
    }
    int cnt=0;
    for(int i=0; i<N; ++i){
        vector<int> temp1, temp2;
        for(int j=0; j<N; ++j){
            temp1.push_back(arr[i][j]);
            temp2.push_back(arr[i][N-j-1]);
        }
        cnt+=f(temp1)||f(temp2);

        // cout << i << " (-), cnt : " << cnt << '\n';

        vector<int> temp3, temp4;
        for(int j=0; j<N; ++j){
            temp3.push_back(arr[j][i]);
            temp4.push_back(arr[N-j-1][i]);
        }
        cnt+=f(temp3)||f(temp4);

        // cout << i << " (|), cnt : " << cnt << '\n';
    }
    cout << cnt << '\n';
}