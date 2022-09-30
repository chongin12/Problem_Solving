#include <bits/stdc++.h>
using namespace std;
vector<int> G[110];
int dir[110]; // 가리키는 자식 (G[i]의 index)
int N; // 노드 개수
int accepted[110]; // 각 노드의 accepted 여부
vector<int> slot[110]; // 리프노드에 쌓인 x들
vector<int> leaves; // 리프노드
int f(int x){
    if(G[x].size()==0) return x;
    int nxt=G[x][dir[x]];
    dir[x]+=1;
    dir[x]%=G[x].size();
    return f(nxt);
}
vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    N=edges.size()+1;
    vector<int> answer;
    for(int i=0; i<edges.size(); ++i){
        int u=edges[i][0], v=edges[i][1];
        G[u].push_back(v);
    }
    int totalAccepted=0;
    for(int i=1; i<=N; ++i){
        dir[i]=0;
        sort(G[i].begin(), G[i].end());
        if(G[i].size()==0){
            leaves.push_back(i);
            if(target[i-1]==0) {
                totalAccepted++;
                accepted[i]=1;
            }
        }
    }
    int cnt=0;
    while(/*totalAccepted <= leaves.size()*/1){
        //이제 x를 넣음
        int a = f(1);
        answer.push_back(a);
        slot[a].push_back(cnt);
        cnt++;
        int t = target[a-1];
        int sz=slot[a].size();
        if(t >= sz && t <= sz*3){
            if(!accepted[a]){
                accepted[a]=1;
                totalAccepted++;
            }
        }
        else if(t > sz*3){
            if(!slot[a].empty()) {
                slot[a].pop_back();
                cnt--;
            }
            else{
                totalAccepted=-1;
            }
            break;
        }
    }
    return answer;
    if(totalAccepted != leaves.size()){
        answer.push_back(-1);
        return answer;
    }
    vector<int> res(cnt);
    for(int i=0; i<leaves.size(); ++i){
        int nowTarget=target[leaves[i]-1];
        int sz=slot[leaves[i]].size();
        for(int j=0; j<sz; ++j){
            int k=slot[leaves[i]][j]; // k번째 x
            if(j==sz-1){
                res[k]=nowTarget;
                break;
            }
            if((nowTarget-1) >= (sz-1) && (nowTarget-1) <= (sz-1)*3){//k를 1로 만들기 가능?
                res[k]=1;
                nowTarget-=1;
            }
            else if((nowTarget-2) >= (sz-1) && (nowTarget-2) <= (sz-1)*3){//k를 2로 만들기 가능?
                res[k]=2;
                nowTarget-=2;
            }
            else{
                res[k]=3;
                nowTarget-=3;
            }
        }
    }
    return res;
}

int main(){
}