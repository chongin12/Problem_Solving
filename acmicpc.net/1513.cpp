#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll MOD=1000007;
ll dp[53][53][53]; // i번째 오락실까지 고려했을 때 j개만큼 거쳐갈 때 마지막 오락실이 k번째일 때 경우의 수
ll cache[53][53];
ll combi[101][101][101]; // combi[i][j][k] : i! / (j! * k!), 단, i==j+k
ll f(pair<ll, ll> A, pair<ll, ll> B){ // A에서 B로 이동하는 경우의 수.
    ll w=B.second-A.second, h=B.first-A.first;
    if(w<0 || h<0){
        return 0;
    }
    return combi[w+h][w][h];
}

void init(){
    combi[0][0][0]=1;
    for(ll i=1; i<101; ++i){
        for(ll j=0; j<=i; ++j){
            ll k=i-j;
            if(j==0 || k==0) combi[i][j][k]=1;
            else combi[i][j][k]=combi[i-1][j][k-1]+combi[i-1][j-1][k];
            combi[i][j][k]%=MOD;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    ll N, M, C; cin>>N>>M>>C;
    vector<pair<ll, ll> > room;
    vector<pair<ll, pair<ll, ll> > > temp;
    for(int i=0; i<C; ++i){
        ll a, b; cin>>a>>b;
        room.push_back({a,b});
        temp.push_back({i, {a,b}});
    }
    //집 : room[C]
    room.push_back({1,1});
    //학원 : room[C+1]
    room.push_back({N,M});
    // cache 채우기
    sort(temp.begin(), temp.end(), [](pair<ll, pair<ll, ll> > A, pair<ll, pair<ll, ll> > B){
        return A.second < B.second;
    });
    for(int i=1; i<C; ++i){
        for(int j=0; j<C-i; ++j){
            int k=j+i;
            ll roomNumj=temp[j].first, roomNumk=temp[k].first;
            cache[roomNumj][roomNumk]=f(room[roomNumj], room[roomNumk]);
            for(int w=j+1; w<=k-1; ++w){
                ll roomNumw=temp[w].first;
                cache[roomNumj][roomNumk]=(cache[roomNumj][roomNumk]+MOD-(cache[roomNumj][roomNumw]*f(room[roomNumw],room[roomNumk]))%MOD)%MOD;
            }
        }
    }
    //cache[C][0~C-1]
    for(int i=0; i<C; ++i){
        ll roomNumi=temp[i].first;
        cache[C][roomNumi]=f(room[C], room[roomNumi]);
        for(int j=0; j<i; ++j){
            ll roomNumj=temp[j].first;
            cache[C][roomNumi]=(cache[C][roomNumi]+MOD-(cache[C][roomNumj]*f(room[roomNumj], room[roomNumi]))%MOD)%MOD;
        }
    }
    //cache[0~C-1][C+1]
    for(int i=0; i<C; ++i){
        cache[i][C+1]=f(room[i], room[C+1]);
        for(int j=0; j<C; ++j){
            if(i==j) continue;
            cache[i][C+1]=(cache[i][C+1]+MOD-(cache[i][j]*f(room[j],room[C+1]))%MOD)%MOD;
        }
    }
    //cache[C][C+1]
    cache[C][C+1]=f(room[C], room[C+1]);
    for(int j=0; j<C; ++j){
        cache[C][C+1]=(cache[C][C+1]+MOD-(cache[C][j]*f(room[j],room[C+1]))%MOD)%MOD;
    }
    dp[0][0][C]=1;
    dp[0][1][0]=cache[C][0];
    //dp 채우기
    for(int i=1; i<C; ++i){
        dp[i][0][C]=1;
        for(int j=1; j<=i+1; ++j){
            // 지금 i번째 오락실을 경로에 포함 안시키는 경우 + 포함 시키는 경우
            // 1. 포함 안시키는 경우
            //dp[i-1][j][0~i]를 그대로 가져온다.
            for(int k=0; k<=i; ++k){
                //dp[i][j][k]채울 예정
                dp[i][j][k]=dp[i-1][j][k];
            }
            // 2. 포함 시키는 경우
            //dp[i-1][j-1][0~i]에서 가져와서 dp[i-1][j-1][i]에 넣는다.
            if(j==1){
                dp[i][j][i]+=cache[C][i];
            }
            else{
                for(int k=0; k<i; ++k){
                    //dp[i][j][i]채울 예정
                    dp[i][j][i]+=dp[i-1][j-1][k]*cache[k][i];
                    dp[i][j][i]%=MOD;
                }
            }
        }
    }
    
    for(int j=0; j<=C; ++j){
        ll res=0;
        if(j==0){
            res=cache[C][C+1];
        }
        else{
            for(int k=0; k<C; ++k){
                res+=dp[C-1][j][k] * cache[k][C+1];
                res%=MOD;
            }
        }
        cout << res << ' ';
    }
    cout << '\n';
}