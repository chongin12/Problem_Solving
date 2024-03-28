#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii=pair<int,int>;
const int INF=987654321;
vector<pii> v;
vector<int> res; // {min}
int dist(pii a, pii b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
	for(int i=0; i<N; ++i){
		res.push_back(0);
	}
	for(int i=0; i<N; ++i){
		int a,b; cin>>a>>b;
		v.push_back({a,b});
		if(i){
			for(int j=0; j<i; ++j){
				int d=dist(v[i],v[j]);
				res[i]=max(res[i],d);
				res[j]=max(res[j],d);
				// cout << j << ", "<<i<<" dist : "<<dist(v[i],v[j])<<'\n';
			}
		}
	}
	int m=INF;
	int midx=0;
	for(int i=0; i<N; ++i){
		if(m>res[i]) {
			m=res[i];
			midx=i;
		}
		// cout << "res["<<i<<"]= "<<res[i]<<'\n';
	}
	cout << v[midx].first<<" "<<v[midx].second<<'\n';
}