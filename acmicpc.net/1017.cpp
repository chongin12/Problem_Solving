#include <bits/stdc++.h>
using namespace std;
const int MN=50;
const int INF=987654321;
int arr[MN];
vector<int> G[MN*2+2];
int c[MN*2+2][MN*2+2], f[MN*2+2][MN*2+2], p[MN*2+2];
vector<int> prime;
int sieve[3000];
void init(){
	for(int i=0; i<MN*2+2; ++i){
		for(int j=0; j<MN*2+2; ++j){
			f[i][j]=0;
		}
	}
}
int maxFlow(int src, int snk){
	int ret=0;
	while(1){
		fill(p, p+MN*2+2, -1); p[src]=src;
		queue<int> q; q.push(src);
		while(!q.empty() && p[snk]==-1){
			int cur=q.front(); q.pop();
			for(auto nxt:G[cur]){
				if(c[cur][nxt]-f[cur][nxt]>0 && p[nxt]==-1){
					q.push(nxt);
					p[nxt]=cur;
				}
			}
		}
		if(p[snk]==-1) break;
		int flow=INF;
		for(int i=snk; i!=src; i=p[i]){
			flow=min(flow, c[p[i]][i]-f[p[i]][i]);
		}
		for(int i=snk; i!=src; i=p[i]){
			f[p[i]][i]+=flow;
			f[i][p[i]]-=flow;
		}
		ret+=flow;
	}
	return ret;
}
int main(){
	int N; cin>>N;
	for(int i=0; i<N; ++i){
		cin>>arr[i];
	}
	for(int i=2; i*i<3000; ++i){
		if(sieve[i]) continue;
		for(int j=i*i; j<3000; j+=i){
			sieve[j]=1;
		}
	}
	for(int i=2; i<3000; ++i){
		if(!sieve[i]) prime.push_back(i);
	}
	int src=MN*2, snk=MN*2+1;
	for(int i=1; i<N; ++i){
		G[src].push_back(i);
		G[i].push_back(src);
		c[src][i]=1;

		G[i+MN].push_back(snk);
		G[snk].push_back(i+MN);
		c[i+MN][snk]=1;
		for(int j=1; j<N; ++j){
			if(i==j) continue;
			if(binary_search(prime.begin(), prime.end(), arr[i]+arr[j])){
				// cout << arr[i] << ", " << arr[j] << '\n';
				G[i].push_back(j+MN);
				G[j+MN].push_back(i);
				c[i][j+MN]=1;
			}
		}
	}
	G[src].push_back(0);
	G[0].push_back(src);
	c[src][0]=1;
	vector<int> res;
	for(int i=1; i<N; ++i){
		G[0].push_back(i+MN);
		G[i+MN].push_back(0);
		if(binary_search(prime.begin(), prime.end(), arr[0]+arr[i])){
			c[0][i+MN]=1;
			init();
			int temp=maxFlow(src,snk);
			// cout << "i : " << i << ", temp : " << temp << '\n';
			if(temp==N-1){
				res.push_back(arr[i]);
			}
			c[0][i+MN]=0;
		}
	}
	if(res.size()==0) cout << "-1\n";
	else{
		sort(res.begin(), res.end());
		for(auto it:res) cout << it << ' ';
		cout << '\n';
	}
}