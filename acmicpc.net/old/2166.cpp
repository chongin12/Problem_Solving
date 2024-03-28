#include <bits/stdc++.h>
using namespace std;
vector<pair<double,double> > v;
int main(){
	int n;cin>>n;
	for(int i=0; i<n; ++i){
		double a,b;cin>>a>>b;
		v.push_back({a,b});
	}
	pair<double,double> temp=v[0];
	v.push_back(temp);
	double r=0, rr=0;
	for(int i=0; i<n; ++i){
		r+=v[i].first*v[i+1].second;
		rr+=v[i].second*v[i+1].first;
	}
	cout<<fixed;
	cout.precision(1);
	cout << abs(r-rr)/2 << '\n';
}