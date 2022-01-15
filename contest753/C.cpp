#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using base = complex<double>;

void fft(vector<base> &a, bool inv){
	int n = a.size(), j = 0;
	for(int i=1; i<n; i++){
		int bit = (n >> 1);
		while(j >= bit){
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
	
	vector<base> roots(n/2);

	for(int i=0; i<n/2; i++)
		roots[i] = base(cos(ang * i), sin(ang * i));

	for(int i=2; i<=n; i<<=1){
		int step = n / i;
		for(int j=0; j<n; j+=i){
			for(int k=0; k<i/2; k++){
				base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
				a[j+k] = u+v;
				a[j+k+i/2] = u-v;
			}
		}
	}
	if(inv) for(int i=0; i<n; i++) a[i] /= n; 
}

vector<i64> multiply(vector<i64> &v, vector<i64> &w, i64 mod){
	int n = 2; while(n < v.size() + w.size()) n <<= 1;
	vector<base> v1(n), v2(n), r1(n), r2(n);
	for(int i=0; i<v.size(); i++)
		v1[i] = base(v[i] >> 15, v[i] & 32767);
	for(int i=0; i<w.size(); i++)
		v2[i] = base(w[i] >> 15, w[i] & 32767);
	fft(v1, 0);
	fft(v2, 0);
	for(int i=0; i<n; i++){
		int j = (i ? (n - i) : i);
		base ans1 = (v1[i] + conj(v1[j])) * base(0.5, 0);
		base ans2 = (v1[i] - conj(v1[j])) * base(0, -0.5);
		base ans3 = (v2[i] + conj(v2[j])) * base(0.5, 0);
		base ans4 = (v2[i] - conj(v2[j])) * base(0, -0.5);
		r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0, 1);
		r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0, 1);
	}
	fft(r1, 1);
	fft(r2, 1);
	vector<i64> ret(n);
	for(int i=0; i<n; i++){
		i64 av = (i64)round(r1[i].real());
		i64 bv = (i64)round(r1[i].imag()) + (i64)round(r2[i].real());
		i64 cv = (i64)round(r2[i].imag());
		av %= mod, bv %= mod, cv %= mod;
		ret[i] = (av << 30) + (bv << 15) + cv;
		ret[i] %= mod;
		ret[i] += mod;
		ret[i] %= mod;
	}
	return ret;
}
vector<i64> lagrange(vector<i64> h, i64 P) {
	int d = (int)h.size()-1; assert(d >= 0);
	auto mul = [P](i64 a, i64 b){
		return a*b%P;
	};
	
	auto ipow = [&mul](i64 a, i64 b) {
		i64 res = 1;
		while(b) {
			if(b&1) res = mul(res, a);
			a = mul(a, a);
			b >>= 1;
		}
		return res;
	};
	
	auto modInv = [&ipow, P](i64 a) {
		return ipow(a, P-2);
	};
	
	vector<i64> fact(4*d+2), invfact(4*d+2);
	fact[0] = 1;
	for(int i=1; i<=4*d+1; ++i)
		fact[i] = mul(i,fact[i-1]);
	
	invfact[4*d+1] = modInv(fact[4*d+1]);
	for(int i=4*d; i>=0; --i)
		invfact[i] = mul(invfact[i+1], i+1);
	
	vector<i64> f(d+1);
	for(int i=0; i<=d; ++i) {
		f[i] = h[i];
		f[i] = mul(invfact[i], f[i]);
		f[i] = mul(invfact[d-i], f[i]);
		if((d-i)%2==1) f[i] = P-f[i];
		if(f[i] == P) f[i] = 0;
	}
	
	vector<i64> inv(4*d+2);
	for(int i=1; i<4*d+2; ++i)
		inv[i] = mul(fact[i-1], invfact[i]);
	
	vector<i64> g(4*d+2);
	g[d+1] = 1;
	for(int j=0; j<=d; ++j) g[d+1] = mul(g[d+1], d+1-j);
	for(int i=d+2; i<4*d+2; ++i)
		g[i] = mul(g[i-1], mul(i, inv[i-d-1]));

	vector<i64> conv = multiply(f, inv, P);

	vector<i64> ret(4*d+2);
	for(int i=0; i<=d; ++i) ret[i] = h[i];
	for(int i=d+1; i<4*d+2; ++i) ret[i] = mul(g[i], conv[i]);

	return ret;
}
vector<i64> squarepoly(vector<i64> poly, i64 P) {
	vector<i64> ss = lagrange(poly, P);
	vector<i64> ret(ss.size()/2);
	auto mul = [P](i64 a, i64 b){
		return a*b%P;
	};
	for(int i=0; i<(int)ss.size()/2; ++i)
		ret[i] = mul(ss[2*i], ss[2*i+1]);
	return ret;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	i64 N,K; cin>>N>>K;
	i64 P=1000000007;
	i64 cnt=0;
	i64 temp=0;
	for(int i=0; i<N; ++i){
		i64 a; cin>>a;
		temp+=a;
		cnt++;
	}
	cnt+=K-temp;
	// 1. Answer! % P
	i64 Answer=cnt;
	i64 d = 1;
	vector<i64> fact_part = {1%P, 2%P};
	while(Answer > d*(d+1)) {
		fact_part = squarepoly(fact_part, P);
		d *= 2;
	}
  
	auto mul = [P](i64 a, i64 b) {
		return (a*b)%P;
	};
	
	i64 ans1 = 1, bucket1 = Answer/d;
	for(int i=0; i<bucket1; ++i) ans1 = mul(ans1, fact_part[i]);
	for(i64 i=bucket1*d+1; i<=Answer; ++i) ans1 = mul(ans1, i);
	
	// cout << "ans1 : " << ans1 << '\n';

	// 2.  Answer2! % D
	i64 Answer2=K-temp;
	i64 d2 = 1;
	vector<i64> fact_part2 = {1%P, 2%P};
	while(Answer2 > d2*(d2+1)) {
		fact_part2 = squarepoly(fact_part2, P);
		d2 *= 2;
	}
  
	auto mul2 = [P](i64 a, i64 b) {
		return (a*b)%P;
	};
	
	i64 ans2 = 1, bucket2 = Answer2/d2;
	for(int i=0; i<bucket2; ++i) ans2 = mul2(ans2, fact_part2[i]);
	for(i64 i=bucket2*d2+1; i<=Answer2; ++i) ans2 = mul2(ans2, i);
	
	// cout << "ans2 : " << ans2 << '\n';



	//ans2 를 나눠야 함. 즉 ans2^(P-2)%P
	
	i64 ans3=1;
	i64 kk=ans2;
	i64 r=P-2;
	while(r!=1){
		if(r%2){
			ans3*=kk;
			ans3%=P;
			r-=1;
		}
		kk=(kk*kk)%P;
		r/=2;
	}
	ans3=(ans3*kk)%P;
	cout << (ans1*ans3)%P << '\n';
	
}