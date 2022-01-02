#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
struct pos{
	ll x,y;
	pos(int x, int y):x(x),y(y){}
};
struct line{
	pos A,B;
	ld a,b;
	// y=ax+b
	int flag=0; // flag가 1 => x=a;
	line(pos A, pos B):A(A),B(B){
		if(B.x-A.x==0) {
			flag=1;
			a=A.x;
			b=0;
		}
		else {
			a=((ld)B.y-A.y)/(B.x-A.x);
			b=(ld)A.y-a*A.x;
		}
	}
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
pair<ld,ld> crossPoint(line l1, line l2){
	// cout << "l1 : "<<l1.a << ", " << l1.b << '\n';
	// cout << "l2 : "<<l2.a << ", " << l2.b << '\n'; 
	if(l1.flag==1){
		ld x=l1.a;
		ld y=l2.a*x+l2.b;
		return {x,y};
	}
	else if(l2.flag==1){
		ld x=l2.a;
		ld y=l1.a*x+l1.b;
		return {x,y};
	}
	else{
		ld x=(l1.b-l2.b)/(l2.a-l1.a);
		ld y=l1.a*x+l1.b;
		return {x,y};
	}
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
	int res=0;
	int l1p3=ccw(p1,p2,p3);
	int l1p4=ccw(p1,p2,p4);
	int l2p1=ccw(p3,p4,p1);
	int l2p2=ccw(p3,p4,p2);
	
	if(l1p3*l1p4==-1 && l2p1*l2p2==-1){
		res=1;
	}
	else if((l1p3*l1p4==0)&&(l2p1*l2p2==0)){
		if(l1p3==0 && l1p4==0 && l2p1==0 && l2p2==0){
			//싹 다 0일때 겹치는조건들
			if((p3<=p1 && p1<=p4)||(p3<=p2 && p2<=p4)){
				res=2;
			}
			else if((p1<=p3 && p3<=p2)||(p1<=p4 && p4<=p2)){
				res=2;
			}
			else{
				res=0;
			}
		}
		else {
			res=1;
		}
	}
	else if((l1p3*l1p4==0)&&(l2p1*l2p2==-1)){
		res=1;
	}
	else if((l1p3*l1p4==-1)&&(l2p1*l2p2==0)){
		res=1;
	}
	else{
		res=0;
	}

	if(res==1){
		cout << "1\n";
		pair<ld,ld> k=crossPoint(line(p1,p2),line(p3,p4));
		cout.precision(10);
		cout << fixed;
		cout << k.first <<" "<<k.second << '\n';
	}
	else if(res==2){
		cout << "1\n";
		if(p1<=p3 && p2==p3){
			cout << p3.x << " " << p3.y << '\n';
		}
		else if(p3<=p1 && p4==p1){
			cout << p1.x << " " << p1.y << '\n';
		}
	}
	else{
		cout << "0\n";
	}
}