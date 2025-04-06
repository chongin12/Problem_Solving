#include <bits/stdc++.h>
using namespace std;
const int L = 0;
const int R = 1;
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
int arr[101][101];
void donate(int x, int y){
    // cout << "donate : " << x << ", " << y << "\n"; 
    int cnt=1;
    for(int i=-1; i<1; ++i){
        for(int j=-1; j<1; ++j){
            int rx=x+i, ry=y+j;
            if(rx>=0 && rx<101 && ry>=0 && ry<101) arr[rx][ry]|=cnt;
            cnt<<=1;
        }
    }
}
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int x, y, dir, g; cin>>x>>y>>dir>>g;
        donate(x,y);
        int px=x+dx[dir];
        int py=y+dy[dir];
        donate(px,py);
        vector<int> v = {};
        for(int i=0; i<g; ++i){
            int curSize = v.size();
            v.push_back(L);
            for(int j=curSize-1; j>=0; --j){
                v.push_back(!v[j]);
            }
        }
        for(auto it:v){
            dir=(dir+(it==L?1:3))%4;
            px+=dx[dir];
            py+=dy[dir];
            donate(px,py);
        }
    }
    int res=0;
    for(int i=0; i<101; ++i){
        for(int j=0; j<101; ++j){
            // cout << arr[i][j] << " ";
            if(arr[i][j]==15) res++;
        }
        // cout << '\n';
    }
    cout << res << '\n';
}

/*

L L R L L R R

(L) (L R) (L L R R) (L L L R R L R R)

 0  1  3  3  3  3  2
 1  7 15 15 15 15 10
 5 15 15 15 15 15 10
 4 12 12 12 12 12  8

 0 1 2
 1 7 10
 4 12 8

*/