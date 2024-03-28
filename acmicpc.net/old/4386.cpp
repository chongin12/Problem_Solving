#include <bits/stdc++.h>
using namespace std;
using pdd=pair<double,double>;
using pdi=pair<double,int>;
vector<pdd> star;
vector<pdi> v; //first : 두 별 사이 거리, second : 별0*100 + 별1
double dist(pdd a, pdd b){
	return (b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second);
}
int p[101];
int find(int x){
	if(x==p[x]) return x;
	return find(p[x]);
}
void unite(int a, int b){
	int A=find(a);
	int B=find(b);
	p[B]=A;
}
int main(){
	int n;cin>>n;
	for(int i=0; i<n; ++i){
		p[i]=i;
		double a,b; cin>>a>>b;
		star.push_back({a,b});
		for(int j=0; j<i; ++j){
			v.push_back({dist(star[i], star[j]),i*1000+j});
		}
	}
	sort(v.begin(), v.end());
	double res=0;
	for(auto it:v){
		double d=it.first;
		int x=it.second/1000;
		int y=it.second%1000;
		if(find(x)!=find(y)){
			unite(x,y);
			res+=sqrt(d);
		}
	}
	cout << fixed;
	cout.precision(3);
	cout << res << '\n';
}