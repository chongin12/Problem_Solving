#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const int MN=1000101;
ll psum[MN], dp[MN], arr[MN], A, B, C;
//dp[i] : i번째 병사까지 포함했을 때 최대 전투력
ll f(ll x){
    return A*x*x+B*x+C;
}
struct LinearFunc {
    ll a,b; // f(x) = ax+b
    double s; // x>=s 시작점.
    LinearFunc(): LinearFunc(1,0) {}
    LinearFunc(ll a, ll b):a(a),b(b),s(-987654321.0) {}
    ll functionValue(ll x){
        return a*x+b+f(x);
    }
};

double cross(LinearFunc l1, LinearFunc l2){
    return ((double)l2.b-l1.b)/(l1.a-l2.a);
}

vector<LinearFunc> lines;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    cin>>A>>B>>C;
    for(int i=1; i<=N; ++i){
        cin>>arr[i];
        psum[i]=psum[i-1]+arr[i];
    }
    dp[1]=f(psum[1]);
    for(int i=2; i<=N; ++i){
        //cout << "dp["<<i-1<<"]="<<dp[i-1]<<'\n';
        // i-1번째 직선 추가.
        // 목표 : dp[i] 채우기
        dp[i]=f(psum[i]);
        LinearFunc newLine(-2*A*psum[i-1], dp[i-1]+A*psum[i-1]*psum[i-1]-B*psum[i-1]);
        while(!lines.empty()){
            newLine.s = cross(newLine, lines.back());
            if(newLine.s > lines.back().s) break;
            lines.pop_back();
        }
        lines.push_back(newLine);
        for(int j=lines.size()-1; j>=0; --j){
            if(lines[j].s <= psum[i]) {
                dp[i]=max(dp[i], lines[j].functionValue(psum[i]));
                break;
            }
        }
        
    }
    cout << dp[N] << '\n';
}