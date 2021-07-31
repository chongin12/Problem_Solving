#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
struct edge {
	int l, r;
	edge(int l, int r) : l(l), r(r) {}
};
struct node {
	int v;
	int g;
	node(int v, int g) : v(v), g(g) {}
};

bool operator<(node a, node b){
	return a.v<b.v;
}
int p[500001];
int pv[500001]; //해당 그룹에서 가장 큰 값
vector<edge> plr; // 해당 그룹의 왼쪽끝, 오른쪽끝
int arr[500001];
priority_queue<node> pq;
string str;
int find(int a){
	if(a<0) return 0;
	if(a==p[a]) return a;
	return p[a] = find(p[a]);
}
void unite(int A, int B){
	int a = find(A);
	int b = find(B);
	pv[a] = max(pv[a], pv[b]);
	plr[a].r = max(plr[a].r, plr[b].r);
	plr[b].r = plr[a].r;
	plr[a].l = min(plr[a].l, plr[b].l);
	plr[b].l = plr[a].l;
	p[b] = a;
	return;
}
int main(){
	int N; cin >> N;
	cin >> str;
	for(int i=0; i<500001; ++i){
		plr.push_back(edge(i, i));
	}
	for(int i=0; i<N; ++i){
		p[i] = i;
		cin >> arr[i];
		pv[i] = arr[i];
		if(i && str[i]==str[i-1]){
			unite(i-1, i);
		}
	}
	int res=0;

	int rg = find(0);
	int lg = find(N-1);
	for(int i=plr[rg].r+1; i<plr[lg].l-1; ++i){
		i = plr[find(i)].r; // 해당 그룹의 맨 오른쪽으로 이동.
		pq.push(node(pv[find(i)], find(i)));
	}


	while(!pq.empty()){
		node pr = pq.top(); pq.pop();
		int g = find(pr.g);
		int v = pv[pr.g];
		if(g==-1) continue;
		res+=v;
		unite(plr[g].l-1, plr[g].r+1);
		p[g] = -1;
	}
	cout << res << '\n';







/*
	while(1){
		
		for(int i=0; i<N; ++i){
			cout << find(i) << " ";
		}
		cout << '\n' << res << '\n';
		
		int lg = find(0); // 가장 왼쪽의 그룹
		int rg = find(N-1); // 가장 오른쪽의 그룹
		if(plr[lg].r+1==plr[rg].l) break;
		int mg=-1, mv=0; // max group, max value
		for(int i=0; i<N; ++i){
			i = plr[find(i)].r; // 해당 그룹의 맨 오른쪽으로 이동.
			if(find(i)==rg) break;
			if(find(i)==lg) continue;
			if(mv<pv[find(i)]) {
				mg = find(i);
				mv = pv[find(i)];
			}
		}
		res += mv;
		//max group은 양 옆의 그룹과 합쳐진다.
		pv[mg]=0;
		unite(plr[mg].l-1, mg);
		unite(plr[mg].r+1, mg);
		
	}
	*/
}