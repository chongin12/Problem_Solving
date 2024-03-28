#include <bits/stdc++.h>
using namespace std;
struct node {
	int x,y,idx;
	node(){x=0,y=0,idx=0;}
	node(int x, int y, int idx):x(x),y(y),idx(idx){}
};
vector<node> arr;
int ccw(node a, node b, node c){
	long long int t=(1LL*a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);
	if(t>0) return 1;
	if(t<0) return -1;
	return 0;
}
bool comp1(node a, node b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}
int dist(node a, node b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool comp2(node a, node b){
	int c=ccw(arr[0],a,b);
	if(c==0) return dist(arr[0],a)<dist(arr[0],b);
	return c>0;
}
void init(){
	arr.clear();
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int c; cin>>c;
	while(c--){
		init();
		int n; cin>>n;
		for(int i=0; i<n; ++i){
			int a,b; cin>>a>>b;
			arr.push_back(node(a,b,i));
		}
		sort(arr.begin(),arr.end(),comp1);
		sort(arr.begin()+1,arr.end(),comp2);
		int k=n-1;
		while(ccw(arr[0],arr[k-1],arr[k])==0) k--;
		reverse(arr.begin()+k,arr.end());
		for(int i=0; i<n; ++i){
			cout << arr[i].idx << ' ';
		}
		cout << '\n';
	}
}