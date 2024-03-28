#include <bits/stdc++.h>
using namespace std;
int arr[51][51];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
vector<int> air;
int main(){
	int r,c,t;cin>>r>>c>>t;
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			cin >> arr[i][j];
			if(arr[i][j]==-1) air.push_back(i);
		}
	}
	while(t--){
		int temp[51][51]={0,};
		for(int i=0; i<r; ++i){
			for(int j=0; j<c; ++j){
				if(arr[i][j]>=5){
					int w=arr[i][j]/5;
					for(int k=0; k<4; ++k){
						int cx=i+dx[k];
						int cy=j+dy[k];
						if(cx>=0 && cx<r && cy>=0 && cy<c && arr[cx][cy]!=-1){
							temp[cx][cy]+=w;
							arr[i][j]-=w;
						}
					}
				}
			}
		}
		for(int i=0; i<r; ++i){
			for(int j=0; j<c; ++j){
				temp[i][j]+=arr[i][j];
			}
		}
		for(int i=0; i<r; ++i){
			for(int j=0; j<c; ++j){
				if(i==0){
					if(j==c-1){
						arr[i][j]=temp[i+1][j];
					}
					else{
						arr[i][j]=temp[i][j+1];
					}
				}
				else if(i==air[0] || i==air[1]){
					if(j>1){
						arr[i][j]=temp[i][j-1];
					}
					else if(j==1) arr[i][j]=0;
				}
				else if(i==r-1){
					if(j==c-1){
						arr[i][j]=temp[i-1][j];
					}
					else{
						arr[i][j]=temp[i][j+1];
					}
				}
				else if((j==0 && i<=air[0]) || (j==c-1 && i>=air[1])){
					arr[i][j]=temp[i-1][j];
				}
				else if((j==0 && i>=air[1]) || (j==c-1 && i<=air[0])){
					arr[i][j]=temp[i+1][j];
				}
				else {
					arr[i][j]=temp[i][j];
				}
			}
		}
	}
	int res=0;
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			if(arr[i][j]>0) res+=arr[i][j];
		}
	}
	cout << res << '\n';
}