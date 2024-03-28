#include <bits/stdc++.h>
using namespace std;
int item[111];
int arr[111][111];
const int INF=987654321;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,r;cin>>n>>m>>r;
	for(int i=1; i<=n; ++i){
		cin>>item[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			arr[i][j]=INF;
		}
		arr[i][i]=0;
	}
	for(int i=1; i<=r; ++i){
		int a,b,l;cin>>a>>b>>l;
		arr[a][b]=min(arr[a][b],l);
		arr[b][a]=min(arr[b][a],l);
	}
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
			}
		}
	}
	int max=0;
	for(int i=1; i<=n; ++i){
		int rr=0;
		for(int j=1; j<=n; ++j){
			if(arr[i][j]<=m) rr+=item[j];
		}
		if(rr>max) max=rr;
	}
	cout << max << '\n';
}