#include <bits/stdc++.h>
using namespace std;
struct pos {
    int x, y;
    pos(int x, int y):x(x),y(y){}
};
double dist(pos a, pos b){
    return sqrt((double)(b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int main(){
    int sx,sy; cin>>sx>>sy;
    pos station(sx,sy);
    int tx,ty; cin>>tx>>ty;
    pos train(tx,ty);
    int dx,dy; cin>>dx>>dy;
    int g=gcd(dx,dy);
    dx=dx/g;
    dy=dy/g;
    while(1){
        pos nxt=train;
        nxt.x+=dx;
        nxt.y+=dy;
        if(dist(station, train)<dist(station, nxt)){
            break;
        }
        train=nxt;
    }
    cout << train.x << " " << train.y << '\n';
}