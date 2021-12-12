#include <bits/stdc++.h>
using namespace std;
struct pos{
	int x,y;
	pos(int x, int y):x(x),y(y){}
};
bool operator>(pos a, pos b){
	if(a.x==b.x) return a.y>b.y;
	return a.x>b.x;
}
bool operator<=(pos a, pos b){
	if(a.x==b.x && a.y==b.y) return true;
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
struct line{
	pos p1,p2;
	line():p1(0,0),p2(0,0){}
	line(pos p1, pos p2):p1(p1),p2(p2){}
};
int ccw(pos a, pos b, pos c){
	int ret=(a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);
	if(ret>0) return 1;
	if(ret<0) return -1;
	return 0;
}
bool cross(line a, line b){
	int ccwa = ccw(a.p1, a.p2, b.p1)*ccw(a.p1, a.p2, b.p2);
	int ccwb = ccw(b.p1, b.p2, a.p1)*ccw(b.p1, b.p2, a.p2);
	if(ccwa == 0 && ccwb == 0){
		return b.p1<=a.p2 && a.p1<=b.p2;
	}
	return ccwa<=0 && ccwb<=0;
}
int p[3001];
int find(int a){
	if(a==p[a]) return a;
	return find(p[a]);
}
void unite(int a, int b){
	int A=find(a);
	int B=find(b);
	p[B]=A;
}
vector<line> vl;
int cnt[3001];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
	for(int i=0; i<N; ++i){
		p[i]=i;	
	}
	for(int i=0; i<N; ++i){
		int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
		pos a(x1,y1), b(x2,y2);
		if(a>b) swap(a,b);
		line l(a,b);
		vl.push_back(l);
		for(int j=0; j<i; ++j){
			//cout << "cross "<<i<<","<<j<<" : "<<cross(vl[i],vl[j]) << '\n';
			if(cross(vl[i],vl[j])) unite(i,j);
		}
	}
	for(int i=0; i<N; ++i){
		cnt[find(i)]++;
	}
	int Max=0;
	int count=0;
	for(int i=0; i<N; ++i){
		if(cnt[i]){
			count++;
			if(cnt[i]>Max){
				Max=cnt[i];
			}
		}
	}
	cout << count << '\n';
	cout << Max << '\n';
}