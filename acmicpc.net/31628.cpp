#include <bits/stdc++.h>
using namespace std;
string arr[10][10];
int main(){
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            cin>>arr[i][j];
        }
    }
    int res=0;
    for(int i=0; i<10; ++i){
        bool flag=true;
        for(int j=1; j<10; ++j){
            if(arr[i][0]!=arr[i][j]) flag=false;
        }
        if(flag) res=1;
    }
    
    for(int i=0; i<10; ++i){
        bool flag=true;
        for(int j=1; j<10; ++j){
            if(arr[0][i]!=arr[j][i]) flag=false;
        }
        if(flag) res=1;
    }
    cout << res << '\n';
}