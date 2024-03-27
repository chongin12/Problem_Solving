#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii=pair<int,int>;
int res=-1;
vector<string> arr;
vector<int> dir;
pii coin1={-1,-1}, coin2;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int N, M;

void f2(int phase, int count){ // count까지 채우기
    if(phase==count){
        int cnt=0;
        int i=0;
        pii now=coin1;
        while(i<count) {
            int nx = now.x + dx[dir[i]];
            int ny = now.y + dy[dir[i]];
            if(nx >= 0 && nx < N && ny>=0 && ny<M){
                if(arr[nx][ny]!='#'){
                    now = {nx,ny};
                }
            }
            else {
                cnt++;
                break;
            }
            ++i;
        }
        i=0;
        now=coin2;
        while(i<count) {
            int nx = now.x + dx[dir[i]];
            int ny = now.y + dy[dir[i]];
            if(nx >= 0 && nx < N && ny>=0 && ny<M){
                if(arr[nx][ny]!='#'){
                    now = {nx,ny};
                }
            }
            else {
                cnt++;
                break;
            }
            ++i;
        }
        if(cnt==1) res=count;
        return;
    }
    for(int i=0; i<4; ++i){
        dir.push_back(i);
        f2(phase+1, count);
        dir.pop_back();
    }
}
void f1(){ // count번 누르기
    for(int i=1; i<=10; ++i){
        f2(0, i);
        if(res!=-1){
            return;
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        arr.push_back(str);
        for(int j=0; j<M; ++j){
            if(str[j]=='o'){
                if(coin1.first == -1){
                    coin1 = {i,j};
                }
                else {
                    coin2 = {i,j};
                }
            }
        }
    }
    f1();
    cout << res << '\n';
}