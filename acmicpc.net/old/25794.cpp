#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii=pair<int,int>;

int main(){
    int X, Y; cin>>X>>Y;
    if(X==Y){
        pii d[7] = {{-1,1},{-1,-1},{-1,-1},{1,-1},{1,-1},{1,1},{-1,1}};
        cout << "7\n";
        int px=0, py=0;
        for(int i=0; i<7; ++i){
            px+=X*d[i].x;
            py+=Y*d[i].y;
            cout << px << " " << py << '\n';
        }
    }
    else if(X==0 || Y==0){
        int k=X+Y;
        pii d[7] = {{0,k},{-k,0},{-k,0},{0,-k},{0,-k},{k,0},{0,k}};
        cout << "7\n";
        int px=0, py=0;
        for(int i=0; i<7; ++i){
            px+=d[i].x;
            py+=d[i].y;
            cout << px << " " << py << '\n';
        }
    }
    else{
        pii d[15] = {
            {X,Y},
            {-Y,-X},
            {-X,Y},
            {-X,-Y},
            {-Y,X},
            {X,-Y},
            {-Y,-X},
            {Y,-X},
            {-X,-Y},
            {Y,X},
            {X,-Y},
            {X,Y},
            {Y,-X},
            {-X,Y},
            {-Y,X}
        };
        cout << "15\n";
        int px=0, py=0;
        for(int i=0; i<15; ++i){
            px+=d[i].x;
            py+=d[i].y;
            cout << px << " " << py << '\n';
        }
    }
}