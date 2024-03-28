#include <bits/stdc++.h>
using namespace std;
vector<int> G[15];
int arr[15];
int visited[15];
int p[15];
int grpsum[15];
void init(){
    for(int i=0; i<15; ++i) visited[i]=0,p[i]=i,grpsum[i]=arr[i];
}
int Find(int x){
    if(x==p[x]) return x;
    return p[x]=Find(p[x]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a==b) return;
    if(a>b) swap(a,b);
    grpsum[a]+=grpsum[b];
    grpsum[b]=0;
    p[b]=a;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    int res=-1;
    for(int i=1; i<=N; ++i){
        cin>>arr[i];
    }
    for(int i=1; i<=N; ++i){
        int n; cin>>n;
        for(int j=0; j<n; ++j){
            int a; cin>>a;
            G[i].push_back(a);
        }
    }
    int limit=1<<N;
    for(int i=1; i<limit; ++i){
        // cout << " i : " << i << '\n';
        init();
        for(int j=1,idx=1; j<limit; j<<=1,idx++){
            if(i&j) {
                visited[idx]=1;
                // cout << "idx : " << idx << '\n';
            }
        }
        for(int j=1; j<=N; ++j){
            for(auto it:G[j]){
                if(visited[it]==visited[j]){
                    Union(it,j);
                }
            }
        }
        int areaA=-1, areaB=-1;
        bool pass=true;
        for(int j=1; j<=N; ++j){
            if(visited[j]==0){
                //areaA
                if(areaA==-1) areaA=Find(j);
                else if(areaA!=Find(j)){
                    pass=false;
                    break;
                }
            }
            else{
                //areaB
                if(areaB==-1) areaB=Find(j);
                else if(areaB!=Find(j)){
                    pass=false;
                    break;
                }
            }
        }
        if(areaA==-1 || areaB==-1){ pass=false; }
        if(pass){
            if(res==-1) res=abs(grpsum[areaA]-grpsum[areaB]);
            else res=min(res,abs(grpsum[areaA]-grpsum[areaB]));
        }
    }
    cout << res << '\n';
}