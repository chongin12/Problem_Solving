#include <bits/stdc++.h>
using namespace std;
int arr[10][10];
int arr2[10][10];
int visit[10][10];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m;
int res=0;
void dfs(int i, int j){
	if(i<0 || i>=n || j<0 || j>=m) return;
	if(visit[i][j] || arr2[i][j]==1) return;
	visit[i][j]=1;
	arr2[i][j]=3;
	for(int k=0; k<4; ++k){
		dfs(i+dx[k],j+dy[k]);
	}
	return;
}
int main(){
	cin>>n>>m;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin >> arr[i][j];
		}
	}
	for(int w1=0; w1<n*m; ++w1){
		if(arr[w1/m][w1%m]!=0) continue;
		for(int w2=w1+1; w2<n*m; ++w2){
			if(arr[w2/m][w2%m]!=0) continue;
			for(int w3=w2+1; w3<n*m; ++w3){
				if(arr[w3/m][w3%m]!=0) continue;
				//안전영역 구하기
				for(int i=0; i<n; ++i){
					for(int j=0; j<m; ++j){
						visit[i][j]=0;
						arr2[i][j]=arr[i][j];
					}
				}
				arr2[w1/m][w1%m]=1;
				arr2[w2/m][w2%m]=1;
				arr2[w3/m][w3%m]=1;
				for(int i=0; i<n; ++i){
					for(int j=0; j<m; ++j){
						if(arr2[i][j]==2) dfs(i,j);
					}
				}
				int r=0;
				
				//cout << w1 << ", " << w2 << ", " << w3 << '\n';
				for(int i=0; i<n; ++i){
					for(int j=0; j<m; ++j){
						//cout << arr2[i][j] << " ";
						if(arr2[i][j]==0) r+=1;
					}
					//cout << '\n';
				}
				
				res=res>r?res:r;
			}
		}
	}
	cout << res << '\n';
}