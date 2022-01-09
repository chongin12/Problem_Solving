#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,w,idx;
	node(int x, int y, int w, int idx):x(x),y(y),w(w),idx(idx){}
};
vector<node> ori;
vector<node> vx;
vector<node> vy;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
	for(int i=0; i<N; ++i){
		int u,v,w; cin>>u>>v>>w;
		ori.push_back(node(u,v,w,i));
		vx.push_back(node(u,v,w,i));
		vy.push_back(node(u,v,w,i));
	}
	sort(vx.begin(), vx.end(), [](node a, node b){
		if(a.x==b.x) return a.y<b.y;
		return a.x<b.x;
	});
	sort(vy.begin(), vy.end(), [](node a, node b){
		if(a.y==b.y) return a.x<b.x;
		return a.y<b.y;
	});
	int chk[41];
	vector<int> ww;
	int res=2e9;
	for(int xi=0; xi<N; ++xi){
		for(int xj=xi; xj<N; ++xj){
			for(int yi=0; yi<N; ++yi){
				for(int yj=yi; yj<N; ++yj){
					
					memset(chk,0,sizeof(chk));
					ww.clear();
					// xi, xj, yi, yj를 이용해서 직사각형을 만들 것.
					int minx=min(min(vx[xi].x,vx[xj].x),min(vy[yi].x,vy[yj].x));
					int maxx=max(max(vx[xi].x,vx[xj].x),max(vy[yi].x,vy[yj].x));
					int miny=min(min(vx[xi].y,vx[xj].y),min(vy[yi].y,vy[yj].y));
					int maxy=max(max(vx[xi].y,vx[xj].y),max(vy[yi].y,vy[yj].y));
					// 이 직사각형에 포함되지 않으면 바깥, 포함되면 안쪽으로 나눔(ww에 넣음).
					int k=(maxx-minx)*2+(maxy-miny)*2;
					int t=0;
					int cnt=0;
					for(int i=0; i<N; ++i){
						int curx=ori[i].x;
						int cury=ori[i].y;
						int curw=ori[i].w;
						if(curx>=minx && curx<=maxx && cury>=miny && cury<=maxy){
							ww.push_back(curw);
						}
						else{
							t+=curw;
							cnt++;
						}
					}
					sort(ww.begin(), ww.end());
					while(k>t && !ww.empty()){
						t+=ww.back();
						cnt++;
						ww.pop_back();
					}
					if(k<=t){
						res=min(res,cnt);
					}
				}
			}
		}
	}
	cout << res << '\n';
}