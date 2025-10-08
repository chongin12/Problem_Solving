#include <bits/stdc++.h>
using namespace std;
int arr[26][26];
int dx[]={1,0,1,-1};
int dy[]={0,1,1,1};
int main(){
    for(int i=0; i<19; ++i){
        for(int j=0; j<19; ++j){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<19; ++i){
        for(int j=0; j<19; ++j){
            if(arr[i][j]==0) continue;
            int k=arr[i][j];
            for(int q=0; q<4; ++q){
                bool flag=true;
                if(i-dx[q]>=0 && j-dy[q]>=0 && arr[i-dx[q]][j-dy[q]]==k) flag=false;
                if(i+dx[q]*5>=0 && j+dy[q]*5>=0 && arr[i+dx[q]*5][j+dy[q]*5]==k) flag=false;
                for(int w=0; w<5; ++w){
                    if(i+dx[q]*w<0 || j+dy[q]*w<0) flag=false;
                    else if(arr[i+dx[q]*w][j+dy[q]*w]!=k) flag=false;
                }
                if(flag){
                    cout << k << '\n';
                    cout << i+1 << " " << j+1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "0\n";
}