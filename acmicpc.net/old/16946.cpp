#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int p[1000001];
int cnt[1000001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int find(int x){
	if(x==p[x]) return x;
	return p[x]=find(p[x]);
}
bool unite(int a, int b){
	int A=find(a);
	int B=find(b);
	if(A!=B) {
		cnt[A]+=cnt[B];
		cnt[B]=0;
		p[B]=A;
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N,M; cin>>N>>M;
	for(int i=0; i<N; ++i){
		string str; cin>>str;
		for(int j=0; j<M; ++j){
			p[i*M+j]=i*M+j;
			arr[i][j] = str[j]-'0';
			if(arr[i][j]==0) cnt[i*M+j]=1;
			if(arr[i][j]==0 && j!=0 && arr[i][j-1]==0) unite(i*M+j-1, i*M+j);
			if(arr[i][j]==0 && i!=0 && arr[i-1][j]==0) unite((i-1)*M+j, i*M+j);
		}
	}
	// for(int i=0; i<N; ++i){
	// 	for(int j=0; j<M; ++j){
	// 		cout << cnt[i*M+j] << " ";
	// 	}
	// 	cout << '\n';
	// }
	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j){
			if(arr[i][j]==1){
				vector<int> visit;
				int res=1;
				for(int k=0; k<4; ++k){
					int cx=i+dx[k];
					int cy=j+dy[k];
					if(cx<0 || cx>=N || cy<0 || cy>=M) continue;
					bool pass=true;
					for(auto it:visit){
						if(it==find(cx*M+cy)) pass=false;
					}
					if(pass){
						visit.push_back(find(cx*M+cy));
						res+=cnt[find(cx*M+cy)];
					}
				}
				//arr[i][j]=res%10;
				cout << res%10 << "";
			}
			else{
				cout << 0 << "";
			}
		}
		cout << '\n';
	}
}