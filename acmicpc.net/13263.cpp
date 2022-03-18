#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
struct LinearFunc{
    ll a,b; // f(x)=ax+b
    double s; // x>=s, 즉 x의 시작점
    LinearFunc(): LinearFunc(1,0){}
    LinearFunc(ll a, ll b):a(a),b(b),s(0){} 
};

// 두 직선의 교점의 x좌표를 구함.
double cross(LinearFunc l1, LinearFunc l2){
    return ((double)l2.b-l1.b)/(l1.a-l2.a);
}

ll a[100001], b[100001], dp[100001];
vector<LinearFunc> line;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        cin >> a[i];
    }
    for(int i=0; i<N; ++i){
        cin >> b[i];
    }
    dp[0]=0;
    for(int i=1; i<N; ++i){ // dp[i] 채우기
        LinearFunc newLine(b[i-1],dp[i-1]);
        while(!line.empty()){
            newLine.s = cross(line.back(), newLine);
            if(newLine.s > line.back().s) break;
            line.pop_back();
        }
        line.push_back(newLine);

        ll x=a[i];
        int lo=0, hi=line.size();
        while(lo<hi-1){
            int mid=(lo+hi)/2;
            if(line[mid].s>x) hi=mid;
            else lo=mid;
        }
        dp[i]=line[lo].a*x+line[lo].b;
    }
    cout << dp[N-1] << '\n';
}