/*
1. 숫자를 정렬한다.
2. 입력으로 들어오는 수를 lower_bound로 찾는다.
3. 찾은 수는 visit[i]에 체크해둔다.
4. union-find 로 i-1, i+1이 visit되었으면 합친다.
5. 합친 수의 부모는 가장 큰 수를 기준으로 해야한다.
*/
#include <bits/stdc++.h>
using namespace std;
int N,M,K;
vector<int> v;
int p[4000001];
int visit[4000001];
int find(int x){
	if(x==p[x]) return x;
	return p[x]=find(p[x]);
}
void unite(int a, int b){
	int A=find(a);
	int B=find(b);
	p[A]=B;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M>>K;
	for(int i=0; i<N; ++i){
		p[i]=i;
	}
	for(int i=0; i<M; ++i){
		int a; cin>>a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<K; ++i){
		int a; cin>>a;
		int pos=lower_bound(v.begin(), v.end(), a+1)-v.begin();
		if(visit[pos]){
			pos=find(pos)+1;
		}
		cout << v[pos] << '\n';
		visit[pos]=1;
		if(pos!=0 && visit[pos-1]){
			unite(pos-1,pos);
		}
		if(pos!=N-1 && visit[pos+1]){
			unite(pos,pos+1);
		}
		
	}
}