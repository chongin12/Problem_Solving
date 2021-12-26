#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<ll,ll>;
ll arr[500001];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll N; cin>>N;
	for(int i=1; i<=N; ++i){
		cin >> arr[i];
	}
	ll res=0;
	vector<pii> st1;
	for(int i=1; i<=N; ++i){
		bool pass=true;
		while(st1.size()!=0){
			if(arr[st1.back().first] < arr[i]){
				res+=st1.back().second+1;
				st1.pop_back();
			}
			else if(arr[st1.back().first] == arr[i]){
				st1.push_back({i,st1.back().second+1});
				pass=false;
				break;
			}
			else{
				st1.push_back({i,1});
				pass=false;
				break;
			}
		}
		if(pass) {
			st1.push_back({i,0});
		}
	}
	while(st1.size()>0){
		res+=st1.back().second;
		st1.pop_back();
	}
	cout << res << '\n';
}