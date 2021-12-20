#include <bits/stdc++.h>
using namespace std;
int visit[3001][3001];
struct node{
	int x, cnt, clip;
	node(int x, int cnt, int clip):x(x),cnt(cnt),clip(clip){}
};
int main(){
	int S; cin>>S;
	queue<node> q;
	q.push(node(1,0,0));
	visit[1][0]=1;
	while(!q.empty()){
		node cur=q.front();
		q.pop();
		if(cur.x == S) {
			cout << cur.cnt << '\n';
			return 0;
		}
		if(cur.x>0 && !visit[cur.x-1][cur.clip]){
			visit[cur.x-1][cur.clip]=1;
		    q.push(node(cur.x-1,cur.cnt+1,cur.clip));
		}
		if(cur.x<S && !visit[cur.x][cur.x]) q.push(node(cur.x,cur.cnt+1,cur.x));
		if(cur.x<=S && !visit[cur.x+cur.clip][cur.clip]) q.push(node(cur.x+cur.clip,cur.cnt+1,cur.clip));
		visit[cur.x][cur.x]=1;
		visit[cur.x+cur.clip][cur.clip]=1;
	}
}