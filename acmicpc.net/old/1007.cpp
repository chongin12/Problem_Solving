#include <iostream>
#include <vector>
#include <cmath>
#define min(x,y) (x)>(y)?(y):(x)
using namespace std;

struct node {
	double x, y;
	node(double x,double y) : x(x), y(y) {}
};
double res;
int visit[21];
void solve(vector<node> v, int N, int cnt, double dx, double dy, int k) {
	//k : 방금 고른 index
	if(cnt == N/2){
		double tmp = sqrt(dx*dx + dy*dy);
		res = min(res, tmp);
		return;
	}
	for(int i=k+1; i<N; ++i){
		if(visit[i]) continue;
		visit[i] = 1;
		solve(v, N, cnt+1, dx-v[i].x*2, dy-v[i].y*2, i);
		visit[i] = 0;
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed;
	cout.precision(12);
	int T; cin >> T;
	while(T--){
		int N; cin >> N;
		res = 1000000000000.0;
		for(int i=0; i<21; ++i){
			visit[i] = 0;
		}
		vector<node> v;
		double dx=0, dy=0;
		for(int i=0; i<N; ++i){
			double x, y; cin >> x >> y;
			v.push_back(node(x, y));
			dx+=x; dy+=y;
		}
		solve(v, N, 0, dx, dy, -1);
		cout << res << '\n';
	}
}