#include <iostream>
using namespace std;
int arr[200][200];
int W, B;
void f(int width, int startX, int startY){
    bool pass=true;
    int k=arr[startX][startY];
    for(int x=0; x<width; ++x){
        if(!pass) break;
        for(int y=0; y<width; ++y){
            if(!pass) break;
            if(arr[startX+x][startY+y]!=k) pass=false;
        }
    }
    if(pass) {
        if(k==0) W++;
        else B++;
        return;
    }
    else {
        f(width/2, startX, startY);
        f(width/2, startX+width/2, startY);
        f(width/2, startX, startY+width/2);
        f(width/2, startX+width/2, startY+width/2);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin >> arr[i][j];
        }
    }
    f(N, 0, 0);
    cout << W << '\n' << B << '\n';
}