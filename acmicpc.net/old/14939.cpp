#include <bits/stdc++.h>
using namespace std;
int temp[10][10];
bool arr[10][10];
void turn(int x, int y){
	arr[x][y]=!arr[x][y];
	if(x>0) arr[x-1][y]=!arr[x-1][y];
	if(y>0) arr[x][y-1]=!arr[x][y-1];
	if(x<9) arr[x+1][y]=!arr[x+1][y];
	if(y<9) arr[x][y+1]=!arr[x][y+1];
}
void init(){
	for(int i=0; i<10; ++i){
		for(int j=0; j<10; ++j){
			arr[i][j] = temp[i][j];
		}
	}
}
int main(){
	int res=987654321;
	for(int i=0; i<10; ++i){
		string str; cin >> str;
		for(int j=0; j<10; ++j){
			if(str[j]=='O') temp[i][j]=true;
			else temp[i][j]=false;
		}
	}
	int cnt;
	for(int k=0; k<1024; ++k){
		init();
		cnt=0;
		for(int j=0; j<10; ++j){
			if(k&(1<<j)){
				turn(0,j);
				cnt++;
			}
		}
		for(int i=1; i<10; ++i){
			for(int j=0; j<10; ++j){
				if(arr[i-1][j]) {
					turn(i,j);
					cnt++;
				}
			}
		}
		bool pass=true;
		for(int i=0; i<10; ++i){
			for(int j=0; j<10; ++j){
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