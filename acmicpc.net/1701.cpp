#include <bits/stdc++.h>
using namespace std;

int main(){
	string str; cin>>str;
	
	int n=str.size();
	int res=0;
	for(int k=0; k<n; ++k){
		//cout << "k : " << k << '\n';
		int pi[10001]={0,};
		int j=0;
		for(int i=k+1; i<n; ++i){
			while(j>0 && str[i]!=str[j+k]){
				j=pi[j-1];
			}
			if(str[i]==str[j+k]){
				pi[i]=++j;
				//cout << "pi["<<i<<"]="<<pi[i]<<'\n';
				res=max(res,pi[i]);
			}
			pi[i-k]=j;
		}
	}
		
	cout << res << '\n';
}