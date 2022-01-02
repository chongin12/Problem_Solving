#include <bits/stdc++.h>
using namespace std;
int arr[200001];
int flag[200001];
int main(){
	int N,K; cin>>N>>K;
	for(int i=0; i<N; ++i){
		cin >> arr[i];
		if((~K)&arr[i]) flag[i]=1;
	}
	flag[N]=1;
	// for(int i=0; i<=N; ++i){
	// 	cout << "flag["<<i<<"]="<<flag[i]<<'\n';
	// }
	int res=arr[0];
	int prev=0;
	if(flag[0]) res=0,prev=1;
	for(int i=1; i<=N; ++i){
		// cout << i<<" : res="<<res<<'\n';
		if(flag[i]){
			if(K==res && prev!=i){
				cout << prev+1 << " " << i << '\n';
				return 0;
			}
			prev=i+1;
			res=0;
		}
		else res=res|arr[i];
	}
	cout << "-1\n";
}