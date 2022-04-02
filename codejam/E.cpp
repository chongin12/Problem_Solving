#include <bits/stdc++.h>
using namespace std;
vector<int> G[100001];
int edge[100001];
int visit[100001];
bool needToSort[100001];
void init(){
    for(int i=0; i<100001; ++i){
        G[i].clear();
        edge[i]=0;
        visit[i]=0;
        needToSort[i]=false;
    }
}
bool chk(int a, int b){ // a와 b가 이웃하면 false
    if(G[a].size()<G[b].size() && !needToSort[b]){
        if(needToSort[a]) {
            sort(G[a].begin(), G[a].end());
            needToSort[a]=false;
        }
        if(binary_search(G[a].begin(), G[a].end(), b)){
            return false;
        }
    }
    else{
        if(needToSort[b]) {
            sort(G[b].begin(), G[b].end());
            needToSort[b]=false;
        }
        if(binary_search(G[b].begin(), G[b].end(), a)){
            return false;
        }
    }
    return true;
}
int main(){
    int T; cin>>T;
    while(T--){
        init();
        int N, K; cin>>N>>K;
        int room, passage;
        int prevRoom;
        bool isTeleported=true;
        int nxtSearch=1;
        for(int i=0; i<=K; ++i){
            cin>>room>>passage;
            edge[room]=passage;
            visit[room]=1;
            if(isTeleported){
                isTeleported=false;
                if(i!=K) cout << "W\n";
            }
            else{
                G[room].push_back(prevRoom);
                G[prevRoom].push_back(room);
                needToSort[room]=true;
                needToSort[prevRoom]=true;
                isTeleported=true;
                while(nxtSearch<=N && visit[nxtSearch]) nxtSearch++;
                if(nxtSearch>N) break;
                if(i!=K) cout << "T "<<nxtSearch<<'\n';
            }
            prevRoom=room;
        }
        int res=0;
        for(int i=1; i<=N; ++i){
            if(visit[i] && edge[i]==G[i].size()) continue;
            if(visit[i]){
                for(int j=i+1; j<=N; ++j){
                    if(G[j].size()==0){
                        G[i].push_back(j);
                        G[j].push_back(i);
                        needToSort[i]=true;
                        needToSort[j]=true;
                    }
                    else{
                        if(visit[j] && edge[j]!=G[j].size() && chk(i, j)){
                            G[i].push_back(j);
                            G[j].push_back(i);
                            needToSort[i]=true;
                            needToSort[j]=true;
                        }
                    }
                    if(edge[i]==G[i].size()) break;
                }
            }
            else{
                if(G[i].size()==0){
                    for(int j=i+1; j<=N; ++j){
                        if(G[j].size()==0 || (visit[j]&&edge[j]!=G[j].size()&&chk(i, j))){
                            G[i].push_back(j);
                            G[j].push_back(i);
                            needToSort[i]=true;
                            needToSort[j]=true;
                            break;
                        }
                    }
                }
            }
        }
        for(int i=1; i<=N; ++i){
            res+=G[i].size();
        }
        cout << "E "<< res/2 << '\n';
        // for(int i=1; i<=N; ++i){
        //     cout << i << " : ";
        //     for(auto it:G[i]){
        //         cout << it << ", ";
        //     }
        //     cout << '\n';
        // }
    }
}