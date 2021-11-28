#include <bits/stdc++.h>
using namespace std;
int n,m;
void left(int [22][22], int );
void right(int [22][22], int );
void up(int [22][22], int );
void down(int [22][22], int );
void f(int arr[22][22]){
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			m=max(m,arr[i][j]);
		}
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int arr[22][22]={};
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin>>arr[i][j];
		}
	}
	left(arr, 5);
	right(arr, 5);
	up(arr, 5);
	down(arr, 5);
	cout << m << '\n';
}
void left(int arr[22][22], int cnt){
	if(cnt<=0) {
		f(arr);
		return;
	}
	int narr[22][22];
	queue<int> q[22];
	for(int i=0; i<n; ++i){
		int st=0;
		for(int j=0; j<n; ++j){
			if(arr[i][j]==0) continue;
			if(st!=0 && st==arr[i][j]){
				q[i].push(st*2);
				st=0;
			}
			else if(st!=0 && st!=arr[i][j]){
				q[i].push(st);
				st=arr[i][j];
			}
			else{
				st=arr[i][j];
			}
		}
		if(st) q[i].push(st);
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(q[i].empty()) {
				narr[i][j]=0;
			}
			else{
				narr[i][j]=q[i].front();
				q[i].pop();
			}
		}
	}
	// for(int i=0; i<n; ++i){
	// 	for(int j=0; j<n; ++j){
	// 		cout<<narr[i][j]<<' ';
	// 	}
	// 	cout << '\n';
	// }
	left(narr, cnt-1);
	right(narr, cnt-1);
	up(narr, cnt-1);
	down(narr, cnt-1);
}
void right(int arr[22][22], int cnt){
	if(cnt<=0) {
		f(arr);
		return;
	}
	int narr[22][22];
	queue<int> q[22];
	for(int i=0; i<n; ++i){
		int st=0;
		for(int j=n-1; j>=0; --j){
			if(arr[i][j]==0) continue;
			if(st!=0 && st==arr[i][j]){
				q[i].push(st*2);
				st=0;
			}
			else if(st!=0 && st!=arr[i][j]){
				q[i].push(st);
				st=arr[i][j];
			}
			else{
				st=arr[i][j];
			}
		}
		if(st) q[i].push(st);
	}
	for(int i=0; i<n; ++i){
		for(int j=n-1; j>=0; --j){
			if(q[i].empty()) {
				narr[i][j]=0;
			}
			else{
				narr[i][j]=q[i].front();
				q[i].pop();
			}
		}
	}
	// for(int i=0; i<n; ++i){
	// 	for(int j=0; j<n; ++j){
	// 		cout<<narr[i][j]<<' ';
	// 	}
	// 	cout << '\n';
	// }
	left(narr, cnt-1);
	right(narr, cnt-1);
	up(narr, cnt-1);
	down(narr, cnt-1);
}
void down(int arr[22][22], int cnt){
	if(cnt<=0) {
		f(arr);
		return;
	}
	int narr[22][22];
	queue<int> q[22];
	for(int i=0; i<n; ++i){
		int st=0;
		for(int j=n-1; j>=0; --j){
			if(arr[j][i]==0) continue;
			if(st!=0 && st==arr[j][i]){
				q[i].push(st*2);
				st=0;
			}
			else if(st!=0 && st!=arr[j][i]){
				q[i].push(st);
				st=arr[j][i];
			}
			else{
				st=arr[j][i];
			}
		}
		if(st) q[i].push(st);
	}
	for(int i=0; i<n; ++i){
		for(int j=n-1; j>=0; --j){
			if(q[i].empty()) {
				narr[j][i]=0;
			}
			else{
				narr[j][i]=q[i].front();
				q[i].pop();
			}
		}
	}
	// for(int i=0; i<n; ++i){
	// 	for(int j=0; j<n; ++j){
	// 		cout<<narr[i][j]<<' ';
	// 	}
	// 	cout << '\n';
	// }
	left(narr, cnt-1);
	right(narr, cnt-1);
	up(narr, cnt-1);
	down(narr, cnt-1);
}
void up(int arr[22][22], int cnt){
	if(cnt<=0) {
		f(arr);
		return;
	}
	int narr[22][22];
	queue<int> q[22];
	for(int i=0; i<n; ++i){
		int st=0;
		for(int j=0; j<n; ++j){
			if(arr[j][i]==0) continue;
			if(st!=0 && st==arr[j][i]){
				q[i].push(st*2);
				st=0;
			}
			else if(st!=0 && st!=arr[j][i]){
				q[i].push(st);
				st=arr[j][i];
			}
			else{
				st=arr[j][i];
			}
		}
		if(st) q[i].push(st);
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(q[i].empty()) {
				narr[j][i]=0;
			}
			else{
				narr[j][i]=q[i].front();
				q[i].pop();
			}
		}
	}
	// for(int i=0; i<n; ++i){
	// 	for(int j=0; j<n; ++j){
	// 		cout<<narr[i][j]<<' ';
	// 	}
	// 	cout << '\n';
	// }
	left(narr, cnt-1);
	right(narr, cnt-1);
	up(narr, cnt-1);
	down(narr, cnt-1);
}