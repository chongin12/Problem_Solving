#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<int,ll>;
vector<ll> ant;
vector<pii> G[100001];
ll visit[100001];
int p[100001];
int res[100001];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0; i<n; ++i){
		ll e; cin>>e;
		ant.push_back(e);
	}
	for(int i=0; i<n-1; ++i){
		int a,b; ll c; cin>>a>>b>>c;
		a--; b--;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	for(int i=0; i<n; ++i){
		visit[i]=-1;
	}
	queue<int> q;
	q.push(0);
	visit[0]=0;
	p[0]=-1;
	while(!q.empty()){
		int cur=q.front(); q.pop();
		for(pii nxt : G[cur]){
			if(visit[nxt.first]==-1){
				p[nxt.first]=cur;
				visit[nxt.first]=visit[cur]+nxt.second;
				q.push(nxt.first);
				int c=nxt.first;
				while(1){
					if(p[c]==-1 || visit[nxt.first]-visit[p[c]]>ant[nxt.first]){
						res[nxt.first]=c;
						break;
					}
					c=p[c];
				}
			}
		}
	}
	for(int i=0; i<n; ++i){
		cout << res[i]+1 << '\n';
	}
}