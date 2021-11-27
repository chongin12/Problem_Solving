#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin>>T;
	int cur,res,n,k,prv;
	while(T--){
		cin>>n;
		res=0;
		int s[100001]={0,};
		pair<int,int> arr[100001]={{0,0},};
		//<phase, cnt>
		for(int i=1; i<=n; ++i){
			cin>>s[i];
		}
		for(int i=1; i<=n; ++i){
			if(s[i]==-1) continue;
			if(i==s[i]) {
				s[i]=-1;
				continue;
			}
			//cout << "i : " <<i << '\n';
			k=0;
			arr[i]={i,++k};
			prv=i;
			cur=s[prv];
			s[prv]=-1;
			while(s[cur]!=-1){
				//cout << "cur : " << cur << "\n";
				//cout << "arr[cur] : " << arr[cur].first << ", " << arr[cur].second << '\n';
				
				arr[cur]={i,++k};
				prv=cur;
				cur=s[prv];
				s[prv]=-1;
			}
			if(arr[cur].first==i){
				k=arr[cur].second-1;
			}
			//cout << "res+="<<k<<'\n';
			res+=k;
		}
		cout << res << '\n';
	}
}