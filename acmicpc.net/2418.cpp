#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[2][201][201];
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
vector<string> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // TARTU라면, 먼저 격자를 다 돌면서 T를 만들 수 있는 곳을 찾기.
    // 그 다음 다시 격자를 다 돌면서 TA를 만들 수 있는 곳을 찾기
    // 그 다음 다시 격자를 다 돌면서 TAR을 만들 수 있는 곳을 찾기. -> R을 먼저 찾고, 인접한 A들의 값을 모두 찾는다.
    int H, W, L; cin>>H>>W>>L;
    for(int i=0; i<H; ++i){
        string str; cin>>str;
        v.push_back(str);
    }
    string target; cin>>target;
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            if(v[i][j]==target[0]) dp[0][i][j]=1;
        }
    }
    for(int w=1; w<L; ++w){
        char ch=target[w];
        char prev=target[w-1];
        for(int i=0; i<H; ++i){
            for(int j=0; j<W; ++j){
                dp[w%2][i][j]=0;
                if(v[i][j]==ch){
                    for(int k=0; k<8; ++k){
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(nx>=0 && nx<H && ny>=0 && ny<W && v[nx][ny]==prev){
                            dp[w%2][i][j]+=dp[(w-1)%2][nx][ny];
                        }
                    }
                }
            }
        }
    }
    ll res=0;
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            res+=dp[(L-1)%2][i][j];
        }
    }
    cout << res << '\n';
}