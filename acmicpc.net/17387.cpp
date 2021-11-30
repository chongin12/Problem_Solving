#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
struct pos{
	ll x,y;
	pos(int x, int y):x(x),y(y){}
};
bool operator<(pos a, pos b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
bool operator==(pos a, pos b){
	return a.x==b.x && a.y==b.y;
}
bool operator<=(pos a, pos b){
	if(a==b) return true;
	return a<b;
}
int ccw(pos a, pos b, pos c){ //a->b->c의 cw, ccw여부를 판별
	ll op= a.x*b.y + b.x*c.y + c.x*a.y;
	op -= a.y*b.x + b.y*c.x + c.y*a.x;
	if(op>0) return 1;
	if(op<0) return -1;
	return 0;
}
int main(){
	ll x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
	ll x3,y3,x4,y4; cin>>x3>>y3>>x4>>y4;

	pos p1=pos(x1,y1);
	pos p2=pos(x2,y2);
	if(p2<p1) {
		pos pt=p1;
		p1=p2;
		p2=pt;
	}

	pos p3=pos(x3,y3);
	pos p4=pos(x4,y4);
	if(p4<p3) {
		pos pt=p3;
		p3=p4;
		p4=pt;
	}

	int l1p3=ccw(p1,p2,p3);
	int l1p4=ccw(p1,p2,p4);
	int l2p1=ccw(p3,p4,p1);
	int l2p2=ccw(p3,p4,p2);
	
	if(l1p3*l1p4==-1 && l2p1*l2p2==-1){
		cout << 1 << '\n';
	}
	else if((l1p3*l1p4==0)&&(l2p1*l2p2==0)){
		if(l1p3==0 && l1p4==0 && l2p1==0 && l2p2==0){
			//싹 다 0일때 겹치는조건들
			if((p3<=p1 && p1<=p4)||(p3<=p2 && p2<=p4)){
				cout << 1 << '\n';
			}
			else if((p1<=p3 && p3<=p2)||(p1<=p4 && p4<=p2)){
				cout << 1 << '\n';
			}
			else{
				cout << 0 << '\n';
			}
		}
		else {
			cout << 1 << '\n';
		}
	}
	else if((l1p3*l1p4==0)&&(l2p1*l2p2==-1)){
		cout << 1 << '\n';
	}
	else if((l1p3*l1p4==-1)&&(l2p1*l2p2==0)){
		cout << 1 << '\n';
	}
	else{
		cout << 0 << '\n';
	}
}