#include <bits/stdc++.h>
using namespace std;
int n,m;
struct pos{
	int x,y;
	pos(int x, int y):x(x),y(y){}
};
vector<pos> house;
vector<pos> chicken;
int chk[20];
int res=987654321;
void calc(){
	int temp[100001]={0,};
	for(int i=0; i<chicken.size(); ++i){
		if(chk[i]==1){
			for(int j=0; j<house.size(); ++j){
				int ch=abs(chicken[i].x-house[j].x)+abs(chicken[i].y-house[j].y);
				if(temp[j]==0 || temp[j]>ch){
					temp[j]=ch;
				}
			}
		}
	}
	int rr=0;
	for(int i=0; i<house.size(); ++i){
		rr+=temp[i];
	}
	res=min(res,rr);
}
void check(int x, int cnt){
	if(cnt==0){
		calc();
		return;
	}
	if(x>=chicken.size()) return;
	for(int i=x; i<chicken.size(); ++i){
		chk[i]=1;
		check(i+1,cnt-1);
		chk[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			int p;cin>>p;
			if(p==1) house.push_back(pos(i,j));
			else if(p==2) chicken.push_back(pos(i,j));
		}
	}
	check(0, m);
	cout << res << '\n';
}