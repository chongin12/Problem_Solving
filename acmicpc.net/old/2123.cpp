#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
pii arr[50001];
vector<pii> v; // {위험도, 인덱스}
int main(){
	int N; cin>>N;
	int sum=0;
	for(int i=0; i<N; ++i){
		int a,b; cin>>a>>b;
		arr[i]={a,b};
		sum+=a;
	}
	for(int i=0; i<N; ++i){
		v.push_back({sum-arr[i].first-arr[i].second,i});
	}
	sort(v.begin(), v.end());
	int res=v[0].first;
	int acc=arr[v[0].second].first;
	for(int i=1; i<v.size(); ++i){
		res=max(res,v[i].first-acc);
		acc+=arr[v[i].second].first;
	}
	cout << res << '\n';
}