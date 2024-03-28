#include <bits/stdc++.h>
using namespace std;
int dp[300001][3]; // 왼, 오, 가만히, 덮은 개수 최대
struct node {
    int h, pos;
    node(int h, int pos):h(h),pos(pos){}
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<node> v;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        if(a!=0){
            v.push_back({a,i});
        }
    }
    for(int i=0; i<v.size(); ++i){
        if(i==0){
            if(v[i].pos>=v[i].h){ // 왼쪽 가능
                dp[0][0]=v[i].h;
            }
            if(v[i].pos+v[i].h<N){ // 오른쪽 가능.
            // 단, 블럭 겹침 여부는 판단 x
            // 오직 범위 벗어나는지만 판단
                dp[0][1]=v[i].h;
            }
            dp[0][2]=1;
        }
        else{
            //1. 왼쪽으로 넘기는게 가능
            //1-1. 이전에 왼쪽으로 넘겼을 때
            if(dp[i-1][0] && v[i-1].pos-1<v[i].pos-v[i].h){
                dp[i][0]=max(dp[i][0], dp[i-1][0]+v[i].h);
            }
            //1-2. 이전에 오른쪽으로 넘겼을 때
            if(dp[i-1][1] && v[i-1].pos+v[i-1].h < v[i].pos-v[i].h){
                dp[i][0]=max(dp[i][1], dp[i-1][1]+v[i].h);
            }
            //1-3. 이전에 가만히 있었을 때
            if(v[i-1].pos < v[i].pos - v[i].h){
                dp[i][0]=max(dp[i][0], dp[i-1][2]+v[i].h);
            }

            //2. 오른쪽으로 넘기는게 가능
            if(v[i].pos+v[i].h<N){
                //2-1. 이전에 왼쪽으로 넘겼을 때
                if(dp[i-1][0]){
                    dp[i][1]=max(dp[i][1], dp[i-1][0]+v[i].h);
                }
                //2-2. 이전에 오른쪽으로 넘겼을 때
                if(dp[i-1][1] && v[i-1].pos+v[i-1].h<=v[i].pos){
                    dp[i][1]=max(dp[i][1], dp[i-1][1]+v[i].h);
                }
                //2-3. 이전에 가만히 있었을 때
                dp[i][1]=max(dp[i][1], dp[i-1][2]+v[i].h);
            }

            //3. 가만히 있는게 가능
            dp[i][2]=max(dp[i][2], dp[i-1][0]+1);
            if(dp[i-1][1] && v[i-1].pos+v[i-1].h<v[i].pos){
                dp[i][2]=max(dp[i][2], dp[i-1][1]+1);
            }
            dp[i][2]=max(dp[i][2], dp[i-1][2]+1);
        }
    }
    cout << N-max({dp[v.size()-1][0], dp[v.size()-1][1], dp[v.size()-1][2]}) << '\n';
}