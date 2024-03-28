/*

어떠한 사건을 처리하려면 경찰차 둘 중 하나는 무조건 움직여야 한다.
경찰차가 있을 수 있는 위치 후보들은 그 전까지 있던 사건들과 (1,1)과 (N,N)이다.
(1,1), (N,N), 모든 사건들 위치 간 이동 거리를 미리 계산해놓는다.
dist[i][j] = i->j로 가는데 필요한 비용.

1~x의 사건을 처리해야 한다.
f(i, pos1, pos2) : i번째 사건~x번째 사건을 처리할 때 거리의 합의 최소
f(i, pos1, pos2) = min(f(i+1, i, pos2)+dist[pos1][i], f(i+1, pos1, i)+dist[pos2][i])
즉, pos1이 i로 이동하거나 pos2가 i로 이동하거나.
f(x, pos1, pos2) : x번째 사건을 처리할 때 거리의 합의 최소
f(x, pos1, pos2) = min(dist[pos1][x], dist[pos2][x])
*/
#include <bits/stdc++.h>
using namespace std;
int N,W;
int dist[1011][1011];
int dp[1011][1011]; // dp[i][j]:경찰차1은 i, 경찰차2는 j에 있을 때 사건을 끝까지 해결하는데 이동하는 거리의 합의 최소.
struct pos{
	int x,y;
	pos(int x, int y):x(x),y(y){}
};
int distance(pos a, pos b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}
vector<pos> v;
int f(int x, int pos1, int pos2){ // x, pos1, pos2 모두 사건의 번호로 지정
	if(dp[pos1][pos2]!=-1) return dp[pos1][pos2];
	if(x==W+1){ // 마지막 사건
		return dp[pos1][pos2]=min(dist[pos1][x], dist[pos2][x]);
	}
	return dp[pos1][pos2]=min(f(x+1, x, pos2)+dist[pos1][x], f(x+1, pos1, x)+dist[pos2][x]);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>N>>W;
	for(int i=0; i<1010; ++i){
		for(int j=0; j<1010; ++j){
			dp[i][j] = -1;
		}
	}
	v.push_back(pos(1,1)); // 0번째 사건
	v.push_back(pos(N,N)); // 1번째 사건
	for(int i=1; i<=W; ++i){
		int a,b; cin>>a>>b;
		pos p(a,b);
		v.push_back(p);
	}
	for(int i=0; i<W+2; ++i){
		for(int j=0; j<W+2; ++j){
			if(i==j) continue;
			if(dist[i][j]) continue;
			dist[i][j]=distance(v[i],v[j]);
			dist[j][i]=dist[i][j];
			//cout << "dist["<<i<<"]["<<j<<"]="<<dist[i][j]<<'\n';
		}
	}
	cout << f(2, 0, 1) << '\n';
	for(int i=0; i<W+2; ++i){
		dp[i][W+1]=0;
		dp[W+1][i]=0;
	}
	int p1=0, p2=1, dest=2; // p1:경찰차1, p2:경찰차2, dest:방문할 곳
	while(dest!=W+2){
		if(dp[p1][p2]==dp[dest][p2]+dist[p1][dest]){
			cout << 1 << '\n';
			p1=dest;
		}
		else{
			cout << 2 << '\n';
			p2=dest;
		}
		dest++;
	}
}