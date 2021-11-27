#include <bits/stdc++.h>
using namespace std;
int key[26];
string arr[102];
int visit[102][102];
queue<pair<int,int> > door[26];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int h,w,res=0;

int f(char c){
	if(c>='a' && c<='z') return c-'a';
	else if(c>='A' && c<='Z') return c-'A';
	return -1;
}
void dfs(int x, int y){
	if(x<0 || x>=h || y<0 || y>=w || visit[x][y]) return;
	char cur=arr[x][y];
	if(cur=='*') return;
	visit[x][y]=1;
	//cout << "dfs("<<x<<","<<y<<")\n";
	if(cur>='a'&&cur<='z'){
		key[f(cur)]=1;
		while(!door[f(cur)].empty()){
			pair<int,int> front=door[f(cur)].front();
			door[f(cur)].pop();
			visit[front.first][front.second]=0;
			dfs(front.first, front.second);
		}
	}
	else if(cur>='A'&&cur<='Z'){
		if(!key[f(cur)]) {
			door[f(cur)].push({x,y});
			return;
		}
	}
	else if(cur=='$'){
		res++;
	}
	for(int i=0; i<4; ++i){
		int nx=x+dx[i];
		int ny=y+dy[i];
		dfs(nx,ny);
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;cin>>T;
	while(T--){
		for(int i=0; i<102; ++i){
			for(int j=0; j<102; ++j){
				visit[i][j]=0;
			}
			arr[i]="";
		}
		for(int i=0; i<26; ++i){
			key[i]=0;
			while(!door[i].empty()) door[i].pop();
		}
		res=0;
		cin>>h>>w;
		for(int i=0; i<h; ++i){
			cin>>arr[i];
		}
		string keys; cin>>keys;
		if(keys!="0"){
			for(auto it:keys){
				key[f(it)]=1;
			}
		}
		for(int i=0; i<h; ++i){
			for(int j=0; j<w; ++j){
				if(i==0 || i==h-1 || j==0 || j==w-1){
					dfs(i,j);
				}
			}
		}
		cout << res << '\n';
	}
}