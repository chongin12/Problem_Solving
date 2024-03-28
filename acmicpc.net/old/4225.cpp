#include <bits/stdc++.h>
using namespace std;
struct pos{
	long double x, y;
	pos(){x=0,y=0;}
	pos(long double x, long double y):x(x),y(y){}
};
vector<pos> v;
int ccw(pos a, pos b, pos c){
	long double t=(a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);
	if(t>0) return 1;
	if(t<0) return -1;
	return 0;
}
long double ccwval(pos a, pos b, pos c){
	long double t=(a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);
	return t;
}
long double posDist(pos a, pos b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool comp1(pos a, pos b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}
bool comp2(pos a, pos b){
	int cw=ccw(v[0],a,b);
	if(cw==0) return posDist(v[0], a) < posDist(v[0],b);
	return cw>0;
}
long double dist(pos a, pos b, pos c){//a,b 직선과 c와의 거리를 구함.
	if(a.x==b.x && a.y==b.y) return sqrt((c.x-a.x)*(c.x-a.x)+(c.y-a.y)*(c.y-a.y));
	long double d=abs(ccwval(a,b,c));
	d/=sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
	return d;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int tc=0;
	while(1){
		tc++;
		int n; cin>>n;
		if(n==0) return 0;
		v.clear();
		for(int i=0; i<n; ++i){
			long double a,b; cin>>a>>b;
			v.push_back(pos(a,b));
		}
		long double res=-1;
		sort(v.begin(),v.end(),comp1);
		sort(v.begin()+1,v.end(),comp2);
		vector<int> st;
		st.push_back(0);
		st.push_back(1);
		int next=2;
		for(int i=2; i<n; ++i){
			while(st.size()>=2){
				int first,second;
				second=st.back();
				st.pop_back();
				first=st.back();
				if(ccw(v[first],v[second],v[i])>0){
					st.push_back(second);
					break;
				}
			}
			st.push_back(i);
		}
		st.push_back(0);
		for(int i=1; i<st.size(); ++i){
			//i-1과 i를 이은 직선
			long double temp=-1;
			for(int j=0; j<st.size(); ++j){
				// 점 하나를 선택해서 직선과의 거리를 구함.
				// 이 거리의 최대값을 구하고 res와 비교한다.
				if(j==i-1 || j==i) continue;
				temp=max(temp,dist(v[st[i-1]],v[st[i]],v[st[j]]));
			}
			if(temp!=-1) {
				if(res==-1) res=temp;
				else res=min(res,temp);
			}
		}
		cout << fixed;
		cout.precision(2);
		res+=0.00499999999;
		cout << "Case "<<tc<<": "<<res << '\n';
	}
}