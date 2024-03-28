#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int arr[51][51];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int INF = 987654321;
vector<pii> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>N>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>arr[i][j];
            if(arr[i][j]==2) {
                v.push_back({i,j});
            }
        }
    }
    vector<int> temp(v.size(), 0);
    for(int i=0; i<M; ++i){
        temp[i]=1;
    }
    sort(temp.begin(), temp.end());
    int result = INF;
    do {
        int a[51][51] = {0,};
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(arr[i][j]==2) a[i][j]=0;
                else if(arr[i][j]==1) a[i][j]=1;
                else a[i][j]=0;
            }
        }
        queue<pii> q;
        for(int i=0; i<v.size(); ++i){
            if(temp[i]){
                a[v[i].first][v[i].second]=2;
                q.push({v[i].first,v[i].second});
            }
        }
        while(!q.empty()){
            pii cur = q.front(); q.pop();
            int curValue = a[cur.first][cur.second];

            for(int i=0; i<4; ++i){
                int nx=cur.first+dx[i];
                int ny=cur.second+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<N && a[nx][ny]!=1){
                    if(a[nx][ny]==0 || a[nx][ny]>curValue+1){
                        a[nx][ny]=curValue+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        int res=0;
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(a[i][j]==0){
                    res=INF;
                }
                else {
                    res=max(res, a[i][j]);
                }
            }
        }
        result = min(res,result);
    } while(next_permutation(temp.begin(), temp.end()));

    if(result == INF){
        cout << "-1\n";
    }
    else {
        cout << result - 2 << '\n';
    }
}