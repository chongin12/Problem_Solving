#include <bits/stdc++.h>
using namespace std;
int lr[10][10];
int ud[10][10];
int main(){
    int N; cin>>N;
    int x=0, y=0;
    string str; cin>>str;
    for(auto it:str){
        if(it=='D'){
            x+=1;
            if(x>=N){
                x-=1;
                continue;
            }
            ud[x-1][y]++;
            ud[x][y]++;
        }
        else if(it=='U'){
            x-=1;
            if(x<0){
                x+=1;
                continue;
            }
            ud[x+1][y]++;
            ud[x][y]++;
        }
        else if(it=='R'){
            y+=1;
            if(y>=N){
                y-=1;
                continue;
            }
            lr[x][y-1]++;
            lr[x][y]++;
        }
        else if(it=='L'){
            y-=1;
            if(y<0){
                y+=1;
                continue;
            }
            lr[x][y+1]++;
            lr[x][y]++;
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(lr[i][j]&&ud[i][j]){
                cout << "+";
            }
            else if(lr[i][j]){
                cout << "-";
            }
            else if(ud[i][j]){
                cout << "|";
            }
            else{
                cout << ".";
            }
        }
        cout << '\n';
    }
}