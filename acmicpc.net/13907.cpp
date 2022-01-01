#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int INF=987654321;
vector<pii> G[1001];
int dist[1001][1001];// dist[i][j] : S~i 최단경로(간선을 j개 썼을 때)
pii maxDist[1001]; // maxDist[i] : {S~i최단경로, 그때의 cnt값} 
// => 최단경로도 더 크거나 같고, cnt값도 더 크거나 같으면 볼 필요가 없음.
int tax[30001];
struct node{
	int dist, nod, cnt; // cnt : 사용 한 간선의 개수
	node(int dist, int nod, int cnt):dist(dist),nod(nod),cnt(cnt){}
};
struct comp{
	bool operator()(node a, node b){
		if(a.dist==b.dist) return a.cnt<b.cnt;
		return a.dist<b.dist;
	}
};
void init(){
	for(int i=0; i<1001; ++i){
		for(int j=0; j<1001; ++j){
			dist[i][j]=INF;
		}
		maxDist[i]={INF, 0};
		G[i].clear();
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	init();
	int N,M,K; cin>>N>>M>>K;
	int S,D; cin>>S>>D;
	for(int i=0; i<M; ++i){
		int a,b,w; cin>>a>>b>>w;
		G[a].push_back({b,w});
		G[b].push_back({a,w});
	}
	for(int i=0; i<K; ++i){
		cin>> tax[i];
	}

	priority_queue<node, vector<node>, comp > pq;
	pq.push(node(0,S,0));
	dist[S][0]=0;
	maxDist[S]={0,0};
	while(!pq.empty()){
		node cur=pq.top(); pq.pop();
		int curNode=cur.nod;
		int curDist=cur.dist;
		int curCnt=cur.cnt;

		for(pii nxt:G[curNode]){
			int nxtNode=nxt.first;
			int nxtDist=nxt.second;
			if(dist[nxtNode][curCnt+1] > dist[curNode][curCnt] + nxtDist && !(maxDist[nxtNode].first<=dist[curNode][curCnt] + nxtDist && maxDist[nxtNode].second<=curCnt+1)){
				dist[nxtNode][curCnt+1] = dist[curNode][curCnt] + nxtDist;
				maxDist[nxtNode]={dist[curNode][curCnt] + nxtDist,curCnt+1};
				pq.push(node(dist[nxtNode][curCnt+1],nxtNode,curCnt+1));
			}
		}
	}
	vector<pii> v;
	int m=INF;
	for(int i=0; i<1001; ++i){
		// cout << "dist["<<D<<"]["<<i<<"]="<<dist[D][i]<<'\n';
		if(dist[D][i]!=INF) {
			v.push_back({dist[D][i],i});
			m=min(m,dist[D][i]);
		}
	}
	cout << m << '\n';
	for(int i=0; i<K; ++i){
		m=INF;
		for(int j=0; j<v.size(); ++j){
			v[j].first+=v[j].second*tax[i];
			m=min(m,v[j].first);
		}
		cout << m << '\n';
	}
}