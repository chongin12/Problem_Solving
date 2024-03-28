#include <bits/stdc++.h>
using namespace std;
string arr[101];
int main(){
    int n; cin>>n;
    int g=0, s=0;
    for(int i=0; i<n; ++i){
        cin>>arr[i];
        int temp=0;
        for(int j=0; j<n; ++j){
            if(arr[i][j]=='.'){
                temp++;
            }
            if(arr[i][j]=='X'){
                if(temp>=2) g++;
                temp=0;
            }
        }
        if(temp>=2) g++;
    }
    for(int j=0; j<n; ++j){
        int temp=0;
        for(int i=0; i<n; ++i){
            if(arr[i][j]=='.'){
                temp++;
            }
            if(arr[i][j]=='X'){
                if(temp>=2) s++;
                temp=0;
            }
        }
        if(temp>=2) s++;
    }
    cout << g << " " << s << '\n';
}