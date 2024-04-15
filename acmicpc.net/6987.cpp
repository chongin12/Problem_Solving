#include <bits/stdc++.h>
using namespace std;
int order[15][2];
int k[6][3]; // [승리, 무승부, 패배] 횟수
bool flag=false;
void f(int phase) {
    if(phase==15) {
        for(int i=0; i<6; ++i){
            for(int j=0; j<3; ++j){
                if(k[i][j]!=0) return;
            }
        }
        flag=true;
        return;
    }
    int team1 = order[phase][0], team2 = order[phase][1];
    if(k[team1][0]>0 && k[team2][2]>0) {
        k[team1][0]-=1;
        k[team2][2]-=1;
        f(phase+1);
        k[team1][0]+=1;
        k[team2][2]+=1;
    }
    if(flag) return;
    if(k[team1][1]>0 && k[team2][1]>0) {
        k[team1][1]-=1;
        k[team2][1]-=1;
        f(phase+1);
        k[team1][1]+=1;
        k[team2][1]+=1;
    }
    if(flag) return;
    if(k[team1][2]>0 && k[team2][0]>0) {
        k[team1][2]-=1;
        k[team2][0]-=1;
        f(phase+1);
        k[team1][2]+=1;
        k[team2][0]+=1;
    }
}
int main(){
    int cnt=0;
    for(int i=0; i<6; ++i){
        for(int j=i+1; j<6; ++j){
            order[cnt][0]=i;
            order[cnt][1]=j;
            cnt++;
        }
    }
    for(int t=0; t<4; ++t){
        flag=false;
        for(int i=0; i<6; ++i){
            for(int j=0; j<3; ++j){
                cin>>k[i][j];
            }
        }
        f(0);
        if(flag) cout << "1 ";
        else cout << "0 ";
    }
}