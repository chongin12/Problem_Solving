#include <bits/stdc++.h>
using namespace std;
int visit[1000001];
int main(){
	int n,k;cin >>n>>k;
	int rest=987654321;
	int res=0;
	queue<pair<int,int> > q; // (현재좌표,시간)
	q.push({n,0});
	while(!q.empty()){
		pair<int,int> fr = q.front();
		q.pop();
		int cpos=fr.first;
		int ctime=fr.second;
		if(ctime>rest){
			break;
		}
		if(cpos==k){
			res+=1;
			rest=ctime;
		}
		else if(cpos<k) {
			visit[cpos]=1;
			if(visit[cpos+1]==0) q.push({cpos+1,ctime+1});
			if(cpos-1>=0 && visit[cpos-1]==0) q.push({cpos-1,ctime+1});
			if(visit[cpos*2]==0) q.push({cpos*2,ctime+1});
		}
		else {
			q.push({cpos-1,ctime+1});
		}
	}
	cout << rest << '\n' << res << '\n';
}