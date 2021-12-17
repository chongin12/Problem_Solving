#include <bits/stdc++.h>
using namespace std;
int dr[5]={0,-1,1,0,0};
int dc[5]={0,0,0,1,-1};
struct node{
	int s,d,z;
	node(){s=-1,d=-1,z=-1;}
	node(int s, int d, int z):s(s),d(d),z(z){}
};
int R,C,M; 
node arr[101][101];
node temparr[101][101];
const node initnode(-1,-1,-1);
void move(int i, int j){
	node temp=arr[i][j];
	arr[i][j]=initnode;
	int r=i+dr[temp.d]*temp.s;
	int c=j+dc[temp.d]*temp.s;
	if(r<0 || r>=R) {
			
		while(r<0 || r>=R){
			//cout << "while r : " << r << '\n';
			if(r<0){
				r=-r;
			}
			else{
				r=2*R-r-2;
			}
			if(temp.d==1) temp.d=2;
			else if(temp.d==2) temp.d=1;
		}
	} 
	else if(c<0 || c>=C) {
			
		while(c<0 || c>=C){
			//cout << "while c : " << c << "->";
			if(c<0){
				c=-c;
			}
			else{
				c=2*C-c-2;
			}
			//cout << c << '\n';
			if(temp.d==3) temp.d=4;
			else if(temp.d==4) temp.d=3;
		}
	}
	if(temparr[r][c].s!=-1){ // 이미 자리에 상어가 들어와 있을 때
		if(temparr[r][c].z < temp.z){
			temparr[r][c]=temp;
			// cout << r << ", "<<c<<" : ";
			// cout << "먹힘!\n";
		}
	}
	else{
		temparr[r][c]=temp;
	}
}
int res=0;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i=0; i<101; ++i){
		for(int j=0; j<101; ++j){
			arr[i][j]=node();
		}
	}
	cin>>R>>C>>M;
	for(int i=0; i<M; ++i){
		int r,c,s,d,z; cin>>r>>c>>s>>d>>z;
		if(d==1||d==2){
			arr[r-1][c-1]=node(s%((R-1)*2),d,z);
		}
		else{
			arr[r-1][c-1]=node(s%((C-1)*2),d,z);
		}
		// cout << r-1 <<", "<<c-1<<" : ";
		// cout << arr[r-1][c-1].s<<", "<<arr[r-1][c-1].d<<", "<<arr[r-1][c-1].z<<'\n';
		
	}
	for(int k=0; k<C; ++k){
		// for(int i=0; i<R; ++i){
		// 	for(int j=0; j<C; ++j){
		// 		if(arr[i][j].s!=-1) cout << arr[i][j].d << " ";
		// 		else cout << 0 << ' ';
		// 	}
		// 	cout << '\n';
		// }
		// cout << " k : "<<k<<'\n';
		for(int i=0; i<R; ++i){
			if(arr[i][k].s!=-1){
				res+=arr[i][k].z;
				// cout << "res+="<<arr[i][k].z<<'\n';
				arr[i][k]=initnode;
				break;
			}
		}
		for(int i=0; i<R; ++i){
			for(int j=0; j<C; ++j){
				temparr[i][j]=node();
			}
		}
		for(int i=0; i<R; ++i){
			for(int j=0; j<C; ++j){
				if(arr[i][j].s!=-1){
					move(i,j);
				}
			}
		}
		for(int i=0; i<R; ++i){
			for(int j=0; j<C; ++j){
				arr[i][j]=temparr[i][j];
			}
		}
		// cout << "---\n";
	}
	cout << res << '\n';
}