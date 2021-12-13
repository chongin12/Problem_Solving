/*
만약 입력 들어온 값의 게이트가 이미 차있으면, 대푯값으로 이동한다.
이 대푯값이 1이면 들어갈 수 없으므로 끝낸다.
대푯값-1에 비행기를 넣고, 대푯값-1과 대푯값 두 그룹을 합친다.
만약 대푯값-2>=1이고 cnt[대푯값-2]가 1 이상이면 대푯값-2, 대푯값-1두 그룹을 합친다. 
*/
#include <bits/stdc++.h>
using namespace std;
int p[101001];
int visit[101001];
int find(int x){
	if(x==p[x]) return x;
	return p[x]=find(p[x]);
}
void unite(int a, int b){
	int A=find(a);
	int B=find(b);
	p[B]=A;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i=1; i<101001; ++i){
		p[i]=i;
	}
	int G,P; cin>>G>>P;
	int a,f1,f2,f3;
	for(int i=0; i<P; ++i){
		cin>>a;
		if(visit[a]==0){
			visit[a]=1;
			f1=find(a+1);
			f2=find(a-1);
			if(visit[f2]) unite(f2,a);
			if(visit[f1]) unite(a,f1);
		}
		else{
			a=find(a);
			if(a==1){
				cout << i << '\n';
				return 0;
			}
			visit[--a]=1;
			f3=find(a-1);
			if(visit[f3]){
				unite(f3,a);
			}
			unite(a,a+1);
		}
	}
	cout << P << '\n';
}