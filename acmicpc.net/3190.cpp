#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int arr[101][101];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int dir=0;
int changeDir[10001];
deque<pii> dq;
int main(){
    int N, K; cin>>N>>K;
    for(int i=0; i<K; ++i){
        int a,b; cin>>a>>b;
        arr[a][b]=1;
    }
    int L; cin>>L;
    for(int i=0; i<L; ++i){
        int x; cin>>x;
        string c; cin>>c;
        changeDir[x]= c=="L"?3:1;
    }
    dq.push_back({1,1});
    arr[1][1]=2;
    for(int t=1; t<=10000; ++t){
        pii nxt = dq.back();
        nxt.first+=dx[dir];
        nxt.second+=dy[dir];
        if(nxt.first<1 || nxt.first>N || nxt.second<1 || nxt.second>N){
            cout << t << '\n';
            return 0;
        }
        dq.push_back({nxt});
        if(arr[nxt.first][nxt.second]==0){
            arr[dq.front().first][dq.front().second]=0;
            dq.pop_front();
        }
        else if(arr[nxt.first][nxt.second]==2){
            cout << t << '\n';
            return 0;
        }
        arr[nxt.first][nxt.second]=2;

        dir=(dir+changeDir[t])%4;
    }
}