#include <bits/stdc++.h>
using namespace std;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int arr[301][301];
int main(){
    int N, M, R; cin>>N>>M>>R;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    int sx=0, sy=0;
    int cn=N, cm=M;
    for(int i=0; i<min(N,M)/2; ++i){
        sx=i, sy=i;
        vector<int> v;
        for(int phase=0; phase<4; ++phase){
            int limit;
            if(phase%2==0) limit=cn;
            else limit=cm;
            for(int j=0; j<limit-1; ++j){
                v.push_back(arr[sx][sy]);
                sx+=dx[phase];
                sy+=dy[phase];
            }
        }
        sx=i, sy=i;
        int idx=(v.size()-R%v.size())%v.size();
        for(int phase=0; phase<4; ++phase){
            int limit;
            if(phase%2==0) limit=cn;
            else limit=cm;
            for(int j=0; j<limit-1; ++j){
                arr[sx][sy]=v[idx];
                idx=(idx+1)%v.size();
                sx+=dx[phase];
                sy+=dy[phase];
            }
        }
        cn-=2, cm-=2;
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}