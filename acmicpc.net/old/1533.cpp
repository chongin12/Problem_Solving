#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll D=1000003;
int N, S, E;
ll T;
struct Mat{
	int size;
	vector<vector<ll> > arr;
	Mat(){size=0;}
	Mat(int n){
		size=n;
		arr=vector<vector<ll> >(n, vector<ll>(n));
	}
	Mat operator * (const Mat &ano){
		Mat ret(size);
		for(int i=0; i<size; ++i){
			for(int j=0; j<size; ++j){
				for(int k=0; k<size; ++k){
					ret.arr[i][j]+=arr[i][k]*ano.arr[k][j];
					ret.arr[i][j]%=D;
				}
			}
		}
		return ret;
	}
};
Mat matProd(Mat a, ll x){ // a^x
	if(x==1) return a;
	Mat ret=matProd(a, x/2);
	ret=ret*ret;
	if(x%2==1) ret = ret * a;
	return ret;
}
int main(){
	cin>>N>>S>>E>>T;
	S--, E--;
	Mat mat(N*5);
	for(int i=0; i<N; ++i){
		for(int j=1; j<5; ++j){
			mat.arr[i*5+j][i*5+j-1]=1;
		}
	}
	for(int i=0; i<N; ++i){
		string str;cin>>str;
		for(int j=0; j<N; ++j){
			ll num=str[j]-'0';
			if(num==0) continue;
			else mat.arr[i*5][j*5+num-1]=1;
		}
	}
	mat = matProd(mat, T);
	cout << mat.arr[S*5][E*5] << '\n';
}