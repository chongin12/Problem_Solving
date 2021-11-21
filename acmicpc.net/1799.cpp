#include <bits/stdc++.h>
using namespace std;
int board[11][11];
int lr[30]; // 왼쪽 위에서 오른쪽 아래로 향하는 대각선. i-j+n
int rl[30]; // 오른쪽 위에서 왼쪽 아래로 향하는 대각선. i+j
int n;
int res=0;
void f(int x, int cnt){
	if(x>=n*n){
		res=max(res,cnt);
		return;
	}
	f(x+2,cnt);
	int r=x/n;
	int c=x%n;
	if(n%2==0){
		if(r%2==1){
			if(c%2==0){
				c+=1;
			}
			else{
				c-=1;
			}
		}
	}
	if(board[r][c]==1 && lr[r-c+n]==0 && rl[r+c]==0){
		lr[r-c+n]=1;
		rl[r+c]=1;
		f(x+2,cnt+1);
		lr[r-c+n]=0;
		rl[r+c]=0;
	}
}
int main(){
	cin>>n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin>>board[i][j];
		}
	}
	int ret=0;
	f(0,0);
	ret+=res;
	res=0;
	for(int i=0; i<30; ++i){
		lr[i]=0;
		rl[i]=0;
	}
	f(1,0);
	//cout << ret << ", " << res << '\n';
	cout << ret+res << '\n';
}