#include <bits/stdc++.h>
using namespace std;
const int MN=50;
const int INF=987654321;
struct edge{
	int v,cost,c,f; // v: 목적지, cost: 기차 요금, c: 사람 수, f: 현재 유량
	edge *rev;
	edge(int v, int cost, int c, int f):v(v),cost(cost),c(c),f(f){}
};
vector<edge*> G[MN+2];

int p[MN+2];
int isInQueue[MN+2], dist[MN+2];
int people[MN+2][MN+2], pay[MN+2][MN+2];
int maxFlow(int src, int snk){
	int ret=0;
	while(1){
		
		fill(p, p+MN+2, -1); p[src]=src;
		fill(isInQueue, isInQueue+MN+2, 0); isInQueue[src]=1;
		fill(dist, dist+MN+2, INF); dist[src]=0;
		edge* path[MN+2]; // i에 도착할 때 선택한 길을 저장해두고 flow추가에서 써먹음.
		queue<int> q; q.push(src);
		while(!q.empty()){
			
			int cur=q.front(); q.pop();
			isInQueue[cur]=0;
			for(int i=0; i<G[cur].size(); ++i){
				edge* nxt=G[cur][i];
				int nxtNode=nxt->v;
				if((nxt->c)-(nxt->f)>0 && dist[nxtNode]>(dist[cur]+nxt->cost)){
					dist[nxtNode]=dist[cur]+nxt->cost;
					p[nxtNode]=cur;
					path[nxtNode]=nxt;
					if(!isInQueue[nxtNode]){
						isInQueue[nxtNode]=1;
						q.push(nxtNode);
					}
				}
			}
		}
		if(p[snk]==-1) break;
		int flow=INF;
		for(int i=snk; i!=src; i=p[i]){
			
			flow=min(flow, path[i]->c-path[i]->f);
		}
		for(int i=snk; i!=src; i=p[i]){
			
			path[i]->f+=flow;
			path[i]->rev->f-=flow;
			ret+=flow*path[i]->cost;
		}
	}
	return ret;
}
void addEdge(int from, int to, int cost, int c){
	edge *e=new edge(to,cost,c,0);
	edge *re=new edge(from,-cost,0,0);
	e->rev=re;
	re->rev=e;
	G[from].push_back(e);
	G[to].push_back(re);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N, P; cin>>N>>P;
	int src=MN, snk=MN+1;
	for(int i=0; i<N; ++i){
		for(int j=i+1; j<N; ++j){
			cin>>people[i][j];
		}
	}
	for(int i=0; i<N; ++i){
		for(int j=i+1; j<N; ++j){
			cin>>pay[i][j];
		}
	}
	addEdge(src,0,0,P);
	for(int i=0; i<N-1; ++i){
		addEdge(i,i+1,0,INF);
	}
	addEdge(N-1,snk,0,INF);
	for(int i=0; i<N; ++i){
		for(int j=i+1; j<N; ++j){
			addEdge(i,j,-pay[i][j],people[i][j]);
		}
	}
	cout << -maxFlow(src, snk) << '\n';
}