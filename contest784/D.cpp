#include <bits/stdc++.h>
using namespace std;
int visit[100001];
int res=0;
int main(){
    int N, S, K, H; cin>>N>>S>>K>>H;
    string str; cin>>str;
    for(int i=0; i<str.size()-2; ++i){
        if(visit[i]) continue;
        if(str[i]=='S' && str[i+1]=='K' && str[i+2]=='H'){
            visit[i]=1;
            visit[i+1]=1;
            visit[i+2]=1;
            res++;
        }
    }
    for(int i=0; i<str.size()-1; ++i){
        if(visit[i] || visit[i+1]) continue;
        if(str[i]=='S' && str[i+1]=='K' && H>0){
            visit[i]=1;
            visit[i+1]=1;
            res++;
            H--;
        }
        else if(str[i]=='S' && str[i+1]=='H' && K>0){
            visit[i]=1;
            visit[i+1]=1;
            res++;
            K--;
        }
        else if(str[i]=='K' && str[i+1]=='H' && S>0){
            visit[i]=1;
            visit[i+1]=1;
            res++;
            S--;
        }
    }
    
    res+=min({S, K, H});
    cout << res << '\n';
}