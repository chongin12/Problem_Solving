#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii=pair<int,int>;
pii arr[101][101]; // N : 0, E : 1, S : 2, W : 3
pii coor[101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int A,B; cin>>A>>B;
    int N,M; cin>>N>>M;
    for(int i=0; i<N; ++i){
        int a,b; cin>>a>>b;
        char c; cin>>c;
        int C;
        if(c=='N') C=0;
        if(c=='E') C=1;
        if(c=='S') C=2;
        if(c=='W') C=3;
        arr[b][a]={i+1, C};
        coor[i+1]={b,a};
    }
    for(int i=0; i<M; ++i){
        int a,b; char c;
        cin>>a>>c>>b;
        while(b--){
            if(c=='F'){
                pii cur = coor[a];
                int dir = arr[cur.x][cur.y].second;
                int ni = cur.x + dx[dir];
                int nj = cur.y + dy[dir];
                if(ni<=0 || ni>B || nj<=0 || nj>A){
                    cout << "Robot " << arr[cur.x][cur.y].first << " crashes into the wall\n";
                    return 0;
                }
                if(arr[ni][nj].first != 0){
                    cout << "Robot " << arr[cur.x][cur.y].first << " crashes into robot "<<arr[ni][nj].first << '\n';
                    return 0;
                }
                arr[ni][nj]={a,dir};
                coor[a]={ni,nj};
                arr[cur.x][cur.y]={0,0};
            }
            else if(c=='L'){
                pii cur = coor[a];
                arr[cur.x][cur.y].second += 3;
                arr[cur.x][cur.y].second %= 4;
            }
            else{
                pii cur = coor[a];
                arr[cur.x][cur.y].second += 1;
                arr[cur.x][cur.y].second %= 4;
            }
        }
    }
    cout << "OK\n";
}