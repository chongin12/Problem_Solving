#include <iostream>
#include <string>
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[22][22];
int res=-1;
int alp[26];
int R, C;
bool safe(int x, int y){
	if(x<0 || x>=R) return false;
	if(y<0 || y>=C) return false;
	return true;
}
void dfs(int x, int y, int cnt) {
	//cout << "now : " << x << ", " << y << "  / arr[x][y] : " << arr[x][y] << "  / cnt : " << cnt << '\n';
	bool pass = true;
	for(int i=0; i<4; ++i){
		int px = x + dx[i];
		int py = y + dy[i];
		if(safe(px, py) && !alp[arr[px][py]]){
			alp[arr[px][py]] = 1;
			dfs(px, py, cnt+1);
			pass=false;
			alp[arr[px][py]] = 0;
		}
	}
	if(pass){
		res = max(res, cnt);
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> R >> C;
	for(int i=0; i<R; ++i){
		string str; cin >> str;
		for(int j=0; j<C; ++j){
			arr[i][j] = str[j]-'A';
		}
	}
	alp[arr[0][0]] = 1;
	dfs(0, 0, 0);
	cout << res+1 << '\n';
}