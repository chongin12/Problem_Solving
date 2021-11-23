#include <bits/stdc++.h>
using namespace std;
int arr[10][10];
bool find(int i, int j, int num){
	bool found=false;
	for(int r=0; r<9; ++r){
		if(arr[i][r]==num){
			found=true;
		}
	}
	for(int c=0; c<9; ++c){
		if(arr[c][j]==num){
			found=true;
		}
	}
	int ar=(i/3)*3+j/3;
	for(int a=0; a<3; ++a){
		for(int b=0; b<3; ++b){
			int curr=(ar/3)*3+a;
			int curc=(ar%3)*3+b;
			if(arr[curr][curc]==num){
				found=true;
			}
		}
	}
	return found;
}
bool dfs(int w){
	int i=w/9;
	int j=w%9;
	if(w==9*9){
		return true;
	}
	else if(arr[i][j]!=0) return dfs(w+1);
	else{
		for(int k=0; k<=9; ++k){
			if(find(i,j,k)) continue;
			arr[i][j]=k;
			if(dfs(w+1)) return true;
			arr[i][j]=0;
		}
	}
	return false;
}
int main(){
	for(int i=0; i<9; ++i){
		string str;cin>>str;
		for(int j=0; j<9; ++j){
			arr[i][j]=str[j]-'0';
		}
	}
	dfs(0);
	for(int i=0; i<9; ++i){
		for(int j=0; j<9; ++j){
			cout << arr[i][j];
		}
		cout << '\n';
	}
}