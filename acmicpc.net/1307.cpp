/*
N이 홀수인 경우:
가운데 위에서부터 시작한다.
항상 오른쪽 위로 진행한다.
한 사이클을 돌면 바로 아래에서 이어서 진행한다.

N이 짝수인 경우:
먼저 순서대로 1부터 N*N까지 전부 채운다.
이 상황에서 대각선 두개는 조건에 맞는다.
가로든 세로든 반대편에서 N/2개씩 스왑한다. 대신, 대각선은 건들지 않는다.
*/
#include <bits/stdc++.h>
using namespace std;
int res[301][301];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
	if(N%2){
		int x=0, y=N/2;
		for(int i=1; i<=N*N; ++i){
			if(x>=N) x-=N;
			if(x<0) x+=N;
			if(y>=N) y-=N;
			if(y<0) y+=N;
			res[x][y]=i;
			if(i%N==0){
				x++;
			}
			else{
				x--;
				y++;
			}
		}
	}
	else if(N%4==0){
		int c=1;
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j){
				res[i][j]=c++;
			}
		}
		for(int i=0; i<N/2; ++i){
			for(int j=0; j<N; ++j){
				if(i<N/4 && j<N/4) continue;
				if(i<N/4 && j>=N/4*3) continue;
				if(i>=N/4 && (j>=N/4 && j<N/4*3)) continue;
				swap(res[i][j], res[N-i-1][N-j-1]);
			}
		}
	}
	else{
		int tempres[301][301]={0,};
		int tempN=N/2;
		int x=0, y=tempN/2;
		for(int i=1; i<=tempN*tempN; ++i){
			if(x>=tempN) x-=tempN;
			if(x<0) x+=tempN;
			if(y>=tempN) y-=tempN;
			if(y<0) y+=tempN;
			tempres[x][y]=i;
			if(i%tempN==0){
				x++;
			}
			else{
				x--;
				y++;
			}
		}
		int area1[301][301]={0,};
		int area2[301][301]={0,};
		int area3[301][301]={0,};
		int area4[301][301]={0,};
		int M=N*N/4;
		for(int i=0; i<tempN; ++i){
			for(int j=0; j<tempN/2; ++j){
				if(i==tempN/2) area1[i][j+1]=3*M;
				else area1[i][j]=3*M;
			}
			for(int j=tempN/2; j<tempN; ++j){
				area2[i][j]=3*M;
			}
		}
		area2[tempN/2][0]=3*M;
		area2[tempN/2][tempN/2]=0;
		for(int i=0; i<tempN; ++i){
			for(int j=0; j<tempN-tempN/2+1; ++j){
				area3[i][j]=2*M;
				area4[i][j]=M;
			}
			for(int j=tempN-tempN/2+1; j<tempN; ++j){
				area3[i][j]=M;
				area4[i][j]=2*M;
			}
		}
		for(int i=0; i<N/2; ++i){
			for(int j=0; j<N/2; ++j){
				res[i][j]=tempres[i][j]+area1[i][j];
			}
		}
		for(int i=0; i<N/2; ++i){
			for(int j=0; j<N/2; ++j){
				res[i+N/2][j]=tempres[i][j]+area2[i][j];
			}
		}
		for(int i=0; i<N/2; ++i){
			for(int j=0; j<N/2; ++j){
				res[i][j+N/2]=tempres[i][j]+area3[i][j];
			}
		}
		for(int i=0; i<N/2; ++i){
			for(int j=0; j<N/2; ++j){
				res[i+N/2][j+N/2]=tempres[i][j]+area4[i][j];
			}
		}
	}
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			cout << res[i][j] << " ";
		}
		cout << '\n';
	}
	/*
	bool flag=true;
	int k;
	if(N%2){
		k=(N*N/2+1)*N;
	}
	else {
		k=(N*N/2+N*N/2+1)*(N/2);
	}
	cout << "k : " << k << '\n';
	int sum=0;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			sum+=res[i][j];
		}
		// cout << sum << '\n';
		if(sum!=k) flag=false;
		sum=0;
		for(int j=0; j<N; ++j){
			sum+=res[j][i];
		}
		// cout << sum << '\n';
		if(sum!=k) flag=false;
		sum=0;
	}
	for(int i=0; i<N; ++i){
		sum+=res[i][i];
	}
	// cout << sum << '\n';
	if(sum!=k) flag=false;
	sum=0;
	for(int i=0; i<N; ++i){
		sum+=res[i][N-i-1];
	}
	// cout << sum << '\n';
	if(sum!=k) flag=false;
	cout << "flag : " << flag << '\n';
	*/
}