#include <bits/stdc++.h>
using namespace std;
int visit[7][7];
bool f(int fromx, int fromy, int tox, int toy){
    if(abs(fromx-tox)==1 && abs(fromy-toy)==2) return true;
    if(abs(fromx-tox)==2 && abs(fromy-toy)==1) return true;
    return false;
}
int main(){
    int prevx=-1, prevy=-1;
    int initx, inity;
    for(int i=0; i<37; ++i){
        string str; int x,y;
        if(i==36){
            x=initx;
            y=inity;
            visit[initx][inity]=0;
        }
        else {
            cin>>str;
            x=str[0]-'A';
            y=str[1]-'1';
        }
        
        if(prevx==-1 && prevy==-1){
            visit[x][y]=1;
            prevx=x;
            prevy=y;
            initx=x;
            inity=y;
        }
        else{
            if(!f(prevx, prevy, x, y)){
                cout << "Invalid\n";
                return 0;
            }
            if(visit[x][y]==1){
                cout << "Invalid\n";
                return 0;
            }
            visit[x][y]=1;
            prevx=x;
            prevy=y;
        }
    }
    cout << "Valid\n";
}