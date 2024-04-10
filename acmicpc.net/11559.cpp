#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<string> arr;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int visited[12][6];
int f1(int x, int y, char ch){
    visited[x][y]=1;
    int ret=1;
    for(int i=0; i<4; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<12 && ny>=0 && ny<6 && !visited[nx][ny] && arr[nx][ny]==ch){
            ret+=f1(nx, ny, ch);
        }
    }
    return ret;
}
void f2(int x, int y, char ch){
    int ret=1;
    arr[x][y]='.';
    for(int i=0; i<4; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<12 && ny>=0 && ny<6 && arr[nx][ny]==ch){
            f2(nx, ny, ch);
        }
    }
}
void f3() {
    for(int i=0; i<6; ++i){
        vector<char> v;
        for(int j=11; j>=0; --j){
            if(arr[j][i]!='.'){
                v.push_back(arr[j][i]);
                arr[j][i]='.';
            }
        }
        for(int j=0; j<v.size(); ++j){
            arr[11-j][i]=v[j];
        }
    }
}
void init(){
    memset(visited, 0, sizeof visited);
}
int main(){
    for(int i=0; i<12; ++i){
        string str; cin>>str;
        arr.push_back(str);
    }
    int res=0;
    while(1){
        init();
        bool flag=true;
        for(int i=0; i<12; ++i){
            for(int j=0; j<6; ++j){
                if(arr[i][j]=='.') continue;
                if(f1(i, j, arr[i][j])>=4){
                    flag=false;
                    f2(i, j, arr[i][j]);
                }
            }
        }
        if(flag) break;
        f3();
        res++;

        // for(int i=0; i<12; ++i){
        //     for(int j=0; j<6; ++j){
        //         cout << arr[i][j];
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    cout << res << '\n';
}