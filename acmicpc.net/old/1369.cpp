#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int INF=987654231;
pii cache[1000001];
int arr[1111][1111];
pii dp[2][1111][1111];
pii padd(pii x, pii y){
	pii ret={x.first+y.first, x.second+y.second};
	if(ret.first>INF) ret.first=INF;
	if(ret.second>INF) ret.second=INF;
	return ret;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
	for(int i=1; i<=1000000; ++i){
		if(i%2==0){
			cache[i]=cache[i/2];
			cache[i].first++;
		}
		else if(i%5==0){
			cache[i]=cache[i/5];
			cache[i].second++;
		}
	}
	
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			cin>>arr[i][j];
			if(arr[i][j]==0){
				continue;
			}
			vector<pii> v2; // {0up, 0left, 1up, 1left}
			vector<pii> v5; // {0up, 0left, 1up, 1left}
			for(int k=0; k<=1; ++k){
				if(arr[i-1][j]!=0) v2.push_back(padd(dp[k][i-1][j], cache[arr[i][j]]));
				if(arr[i-1][j]!=0) v5.push_back(padd(dp[k][i-1][j], cache[arr[i][j]]));
				if(arr[i][j-1]!=0) v2.push_back(padd(dp[k][i][j-1], cache[arr[i][j]]));
				if(arr[i][j-1]!=0) v5.push_back(padd(dp[k][i][j-1], cache[arr[i][j]]));
			}
			if(i==1 && j==1){
				v2.push_back(cache[arr[i][j]]);
				v5.push_back(cache[arr[i][j]]);
			}
			if(v2.empty() || v5.empty()){
				dp[0][i][j]={INF,INF};
				dp[1][i][j]={INF,INF};
			}
			else{
				sort(v2.begin(), v2.end(), [](pii x, pii y){
					if(x.first==y.first) return x.second<y.second;
					return x.first<y.first;
				});
				dp[0][i][j]=v2[0];
				sort(v5.begin(), v5.end(), [](pii x, pii y){
					if(x.second==y.second) return x.first<y.first;
					return x.second<y.second;
				});
				dp[1][i][j]=v5[0];
			}
		}
	}
	int res=min(min(dp[0][N][N].first, dp[0][N][N].second),min(dp[1][N][N].first, dp[1][N][N].second));
	if(arr[N][N]==0){
		cout << 0 << '\n';
	}
	else{
		cout << res << '\n';
	}
}