#include <bits/stdc++.h>
using namespace std;
int arr[10][20];
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        int a=str[0]-'A';
        int b=str[1]-'0';
        if(str.size()==3){
            b=b*10+str[2]-'0';
        }
        arr[a][b-1]=1;
    }
    for(int i=0; i<10; ++i){
        for(int j=0; j<20; ++j){
            if(arr[i][j]) cout << "o";
            else cout << ".";
        }
        cout << '\n';
    }
}