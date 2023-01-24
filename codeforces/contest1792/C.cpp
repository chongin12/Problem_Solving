#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        vector<int> v(N);
        vector<int> visited(N);
        vector<pii> v2;
        for(int i=0; i<N; ++i){
            cin>>v[i];
            v2.push_back({v[i],i});
        }
        sort(v2.begin(), v2.end());
        int v2ptr=0;
        int l=0, r=v.size()-1;
        int left=v.size();
        int temp=0;
        int res=0;
        while(left>=2){
            left-=2;
            int lidx=v2[v2ptr].second;
            v2ptr++;
            int ridx=v2.back().second; v2.pop_back();
            visited[lidx]=1;
            visited[ridx]=1;
            temp+=1;
            if(lidx==l && ridx==r){
                while(visited[l] && l<=r){++l;}
                while(visited[r] && l<=r){--r;}
            }
            else{
                res+=temp;
                temp=0;
                while(visited[l] && l<=r){++l;}
                while(visited[r] && l<=r){--r;}
            }
        }
        std::cout << res << '\n';
    }
}