#include <bits/stdc++.h>
using namespace std;
int n,m;

int res=987654321;
void left(string arr[11], int cnt);
void right(string arr[11], int cnt);
void up(string arr[11], int cnt);
void down(string arr[11], int cnt);
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	string arr[11];
	for(int i=0; i<n; ++i){
		cin>>arr[i];
	}
	up(arr,1);
	left(arr,1);
	right(arr,1);
	down(arr,1);
	if(res==987654321) cout << -1 << '\n';
	else cout << res << '\n';
}
void left(string arr[11], int cnt){
	if(cnt>=11) return;
	string newarr[11];
	int tempRes=-1;
	int k=0;
	bool ret=false;
	for(int i=0; i<n; ++i){
		string temp="";
		bool flag=false;
		for(int j=0; j<m; ++j,++k){
			if(arr[i][j]=='#'){
				k=0;
				flag=false;
				temp+="#";
			}
			else if(arr[i][j]=='R'){
				temp+=".";
				if(flag) {
					if(tempRes!=-2) {
						tempRes=cnt;
						ret=true;
					}
				}
				else temp[j-k+1]='R';
				k-=1;
			}
			else if(arr[i][j]=='B'){
				temp+=".";
				if(flag) {
					tempRes=-2;
					ret=true;
				}
				else temp[j-k+1]='B';
				k-=1;
			}
			else if(arr[i][j]=='O'){
				flag=true;
				temp+="O";
			}
			else{
				temp+=".";
			}
		}
		newarr[i]=temp;
	}
	if(tempRes>0) res=min(res,tempRes);
	else if(!ret){
		// for(int i=0; i<n; ++i){
		// 	cout << newarr[i] << '\n';
		// }
		up(newarr,cnt+1);
		right(newarr,cnt+1);
		down(newarr,cnt+1);
	}
	
}
void right(string arr[11], int cnt){
	if(cnt>=11) return;
	string newarr[11];
	int tempRes=-1;
	int k=0;
	bool ret=false;
	for(int i=0; i<n; ++i){
		string temp="";
		bool flag=false;
		for(int j=m-1; j>=0; --j,++k){
			if(arr[i][j]=='#'){
				k=0;
				flag=false;
				temp+="#";
			}
			else if(arr[i][j]=='R'){
				temp+=".";
				if(flag) {
					if(tempRes!=-2) {
						tempRes=cnt;
						ret=true;
					}
				}
				else temp[m-j-1-k+1]='R';
				k-=1;
			}
			else if(arr[i][j]=='B'){
				temp+=".";
				if(flag) {
					tempRes=-2;
					ret=true;
				}
				else temp[m-j-1-k+1]='B';
				k-=1;
			}
			else if(arr[i][j]=='O'){
				flag=true;
				temp+="O";
			}
			else{
				temp+=".";
			}
		}
		reverse(temp.begin(), temp.end());
		newarr[i]=temp;
	}
	if(tempRes>0) res=min(res,tempRes);
	else if(!ret){
		// for(int i=0; i<n; ++i){
		// 	cout << newarr[i] << '\n';
		// }
		up(newarr,cnt+1);
		left(newarr,cnt+1);
		down(newarr,cnt+1);
	}
	
}
void up(string arr[11], int cnt){
	if(cnt>=11) return;
	string newarr[11];
	int tempRes=-1;
	int k=0;
	bool ret=false;
	for(int i=0; i<m; ++i){
		string temp="";
		bool flag=false;
		for(int j=0; j<n; ++j,++k){
			if(arr[j][i]=='#'){
				k=0;
				flag=false;
				temp+="#";
			}
			else if(arr[j][i]=='R'){
				temp+=".";
				if(flag) {
					if(tempRes!=-2) {
						tempRes=cnt;
						ret=true;
					}
				}
				else temp[j-k+1]='R';
				k-=1;
			}
			else if(arr[j][i]=='B'){
				temp+=".";
				if(flag) {
					tempRes=-2;
					ret=true;
				}
				else temp[j-k+1]='B';
				k-=1;
			}
			else if(arr[j][i]=='O'){
				flag=true;
				temp+="O";
			}
			else{
				temp+=".";
			}
		}
		newarr[i]=temp;
	}
	if(tempRes>0) res=min(res,tempRes);
	else if(!ret){
		string newnewarr[11]={};
		for(int i=0; i<m; ++i){
			for(int j=0; j<n; ++j){
				newnewarr[j]+=newarr[i][j];
			}
		}
		// for(int i=0; i<n; ++i){
		// 	cout << newnewarr[i] << '\n';
		// }
		left(newnewarr,cnt+1);
		right(newnewarr,cnt+1);
		down(newnewarr,cnt+1);
		
	}
}
void down(string arr[11], int cnt){
	if(cnt>=11) return;
	string newarr[11];
	int tempRes=-1;
	int k=0;
	bool ret=false;
	for(int i=0; i<m; ++i){
		string temp="";
		bool flag=false;
		for(int j=n-1; j>=0; --j,++k){
			if(arr[j][i]=='#'){
				k=0;
				flag=false;
				temp+="#";
			}
			else if(arr[j][i]=='R'){
				temp+=".";
				if(flag) {
					if(tempRes!=-2) {
						tempRes=cnt;
						ret=true;
					}
				}
				else temp[n-j-1-k+1]='R';
				k-=1;
			}
			else if(arr[j][i]=='B'){
				temp+=".";
				if(flag) {
					tempRes=-2;
					ret=true;
				}
				else temp[n-j-1-k+1]='B';
				k-=1;
			}
			else if(arr[j][i]=='O'){
				flag=true;
				temp+="O";
			}
			else{
				temp+=".";
			}
		}
		reverse(temp.begin(), temp.end());
		newarr[i]=temp;
	}
	if(tempRes>0) res=min(res,tempRes);
	else if(!ret){
		string newnewarr[11]={};
		for(int i=0; i<m; ++i){
			for(int j=0; j<n; ++j){
				newnewarr[j]+=newarr[i][j];
			}
		}
		// for(int i=0; i<n; ++i){
		// 	cout << newnewarr[i] << '\n';
		// }
		up(newnewarr,cnt+1);
		left(newnewarr,cnt+1);
		right(newnewarr,cnt+1);
		
	}
}