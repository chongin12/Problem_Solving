#include <bits/stdc++.h>
using namespace std;
int dp[1001001];
int main(){
	string T, P;
	getline(cin,T);
	getline(cin,P);
	int n=T.size();
	int m=P.size();
	
	//전처리
	int j=0;
	for(int i=1; i<m; ++i){
		while(j>0 && P[j]!=P[i]){
			j=dp[j-1];
		}
		if(P[j]==P[i]){
			dp[i]=++j;
		}
		//cout << "dp "<<i<<" : "<<dp[i]<<'\n';
	}
	vector<int> v;
	j=0;
	for(int i=0; i<n; ++i){
		while(j>0 && T[i]!=P[j]){
			j=dp[j-1];
		}
		if(P[j]==T[i]){
			if(j==m-1){
				v.push_back(i-j);
				j=dp[j];
			}
			else{
				++j;
			}
		}
		
	}
	cout << v.size() << '\n';
	for(auto it:v){
		cout << it+1 << " ";
	}
	cout << '\n';
}