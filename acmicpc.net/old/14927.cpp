#include <bits/stdc++.h>
using namespace std;
int temp[18][18];
bool arr[18][18];
int N;
void turn(int x, int y){
	arr[x][y]=!arr[x][y];
	if(x>0) arr[x-1][y]=!arr[x-1][y];
	if(y>0) arr[x][y-1]=!arr[x][y-1];
	if(x<N-1) arr[x+1][y]=!arr[x+1][y];
	if(y<N-1) arr[x][y+1]=!arr[x][y+1];
}
void init(){
	for(int i=0; i<18; ++i){
		for(int j=0; j<18; ++j){
			arr[i][j] = temp[i][j];
		}
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int res=987654321;
	cin>>N;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			int a;cin>>a;
			if(a==1) temp[i][j]=true;
		}
	}
	int cnt;
	int MAX=(1<<N);
	for(int k=0; k<MAX; ++k){
		init();
		cnt=0;
		for(int j=0; j<N; ++j){
			if(k&(1<<j)){
				turn(0,j);
				cnt++;
			}
		}
		for(int i=1; i<N; ++i){
			for(int j=0; j<N; ++j){
				if(arr[i-1][j]) {
					turn(i,j);
					cnt++;
				}
			}
		}
		bool pass=true;
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j){
				if(arr[i][j]) {
					pass=false;
					break;
				}
			}
			if(!pass) break;
		}
		if(pass){
			res=min(res,cnt);
		}
	}
	if(res==987654321) cout << "-1\n";
	else cout << res << '\n';
}