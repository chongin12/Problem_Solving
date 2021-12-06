#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int N;

struct pos{
	ll x,y;
	pos(ll x, ll y):x(x),y(y){}
};
vector<pos> v;
pos standard(0,0);
ll dist(pos a, pos b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int ccw(pos a, pos b, pos c){
	ll k=a.x*b.y+b.x*c.y+c.x*a.y;
	k-=(a.y*b.x+b.y*c.x+c.y*a.x);
	if(k>0) return 1;
	if(k<0) return -1;
	return 0;
}
bool comp1(pos a, pos b){ // 가장 아래, 오른쪽이 제일 작도록.
	if(a.y==b.y) return a.x>b.x;
	return a.y<b.y;
}
bool comp2(pos a, pos b){
	int cw=ccw(standard, a, b);
	if(cw==0){
		return dist(standard,a)<dist(standard,b);
	}
	else if(cw==1){
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(int i=0; i<N; ++i){
		ll a,b;cin>>a>>b;
		v.push_back(pos(a,b));
	}
	sort(v.begin(), v.end(), comp1);
	// for(int i=0; i<v.size(); ++i){
	// 	cout << "v["<<i<<"]=("<<v[i].x<<", "<<v[i].y<<")\n";
	// }
	standard=pos(v[0].x,v[0].y);
	sort(v.begin()+1, v.end(), comp2);
	// for(int i=0; i<v.size(); ++i){
	// 	cout << "v["<<i<<"]=("<<v[i].x<<", "<<v[i].y<<")\n";
	// }
	vector<pos> st;
	st.push_back(v[0]);
	for(int i=1; i<v.size(); ++i){
		pos p2=st.back();
		st.pop_back();
		if(st.empty()){
			st.push_back(p2);
			st.push_back(v[i]);
			continue;
		}
		pos p1=st.back();
		st.push_back(p2);
		if(ccw(p1, p2, v[i])>0){
			st.push_back(v[i]);
		}
		else{
			st.pop_back();
			i-=1;
		}
	}
	// cout << st.size() << '\n';
	// while(!st.empty()){
	// 	pos cur=st.back();
	// 	st.pop_back();
	// 	cout << "("<<cur.x<<", "<<cur.y<<")\n";
	// }
	ll res=st.size();
	// st.push_back(st[0]);
	// for(int i=2; i<st.size(); ++i){
	// 	cout << "ccw "<<i-2<<","<<i-1<<","<<i<<" : "<<ccw(st[i-2],st[i-1],st[i])<<'\n';
	// }
	// for(int i=2; i<st.size(); ++i){
	// 	if(ccw(st[i-2],st[i-1],st[i])==0){
	// 		res-=1;
	// 	}
	// }
	// for(int i=0; i<st.size(); ++i){
	// 	cout << "st["<<i<<"] = ("<<st[i].x<<", "<<st[i].y<<")\n";
	// }
	if(ccw(st[st.size()-2], st[st.size()-1], st[0])==0) res-=1;
	cout << res << '\n';
}