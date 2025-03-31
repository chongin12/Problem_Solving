#include <bits/stdc++.h>
using namespace std;
int arr[51][51];
string arr2[51][51];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int main(){
    int r1, c1, r2, c2; cin>>r1>>c1>>r2>>c2;
    if(0>=r1 && 0<=r2 && 0>=c1 && 0<=c2){
        arr[0-r1][0-c1]=1;
    }
    if(0>=r1 && 0<=r2 && 1>=c1 && 1<=c2){
        arr[0-r1][1-c1]=2;
    }
    int r=0, c=1;
    int now=-1, dir=0;
    int cnt=2;
    while(1){
        if(abs(r)>5000) break;
        int temp=abs(now);
        for(int i=0; i<temp; ++i){
            r+=dx[dir];
            c+=dy[dir];
            ++cnt;
            if(r>=r1 && r<=r2 && c>=c1 && c<=c2){
                // cout << "("<<r<<", "<<c<<")="<<cnt<<'\n';
                arr[r-r1][c-c1]=cnt;
            }
        }
        if(now<0) now=-now+1;
        else now*=-1;
        dir=(dir+1)%4;
    }
    int maxLen=0;
    for(int i=0; i<=r2-r1; ++i){
        for(int j=0; j<=c2-c1; ++j){
            arr2[i][j]=to_string(arr[i][j]);
            maxLen=max(maxLen,(int)arr2[i][j].size());
        }
    }
    for(int i=0; i<=r2-r1; ++i){
        for(int j=0; j<=c2-c1; ++j){
            for(int k=0; k<maxLen-arr2[i][j].size(); ++k){
                cout << " ";
            }
            cout << arr2[i][j] << " ";
        }
        cout << '\n';
    }
}