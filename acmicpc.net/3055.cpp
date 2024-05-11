#include <bits/stdc++.h>
using namespace std;
vector<string> arr;
char narr[51][51];
int visited[51][51];
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int R, C; cin>>R>>C;
    int si, sj; // source
    int di, dj; // destination
    int wi, wj; // water
    for(int i=0; i<R; ++i){
        string str; cin>>str;
        arr.push_back(str);
        for(int j=0; j<C; ++j){
            if(str[j]=='D') {
                di=i, dj=j;
                arr[i][j]='.';
            }
            else if(str[j]=='S') {
                si=i, sj=j;
            }
            else if(str[j]=='*'){
                wi=i, wj=j;
            }
        }
    }
    for(int t=1; ; ++t){
        bool isMoved = false;

        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                if(arr[i][j]!='.') continue;
                int cnt=0; // 옆에 뭐가 있는지, *는 1, S는 2로 OR함.
                for(int k=0; k<4; ++k){
                    int nx=i+dx[k], ny=j+dy[k];
                    if(nx>=0 && nx<R && ny>=0 && ny<C && arr[nx][ny]!='X'){
                        if(arr[nx][ny]=='*') cnt|=1;
                        if(arr[nx][ny]=='S') cnt|=2;
                    }
                }
                if(i==di && j==dj && (cnt&2)) {
                    narr[i][j]='S';
                }
                else if((cnt==1 || cnt==3) && !(i==di && j==dj)){
                    narr[i][j]='*';
                }
                else if(cnt==2){
                    narr[i][j]='S';
                    isMoved=true;
                }
            }
        }

        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                if(narr[i][j]!=0) {
                    arr[i][j]=narr[i][j];
                    narr[i][j]=0;
                    if(i==di && j==dj && arr[i][j]=='S'){
                        cout << t << '\n';
                        return 0;
                    }
                }
            }
        }

        // cout << '\n';
        // for(int i=0; i<R; ++i){
        //     for(int j=0; j<C; ++j){
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << '\n';
        // }


        if(!isMoved) break;
    }
    cout << "KAKTUS\n";
}