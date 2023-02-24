#include <bits/stdc++.h>
using namespace std;
const int MN=1000001;
vector<int> v;
int isErased[MN];
vector<int> prime;
vector<pair<int,int> > factorization[101];
int temp[80000];
vector<pair<int,int> > resFactor;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        v.push_back(a);
    }
    for(int i=2; i*i<MN; ++i){
        if(!isErased[i]){
            for(int j=i*i; j<MN; j+=i){
                isErased[j]=1;
            }
        }
    }
    for(int i=2; i<MN; ++i){
        if(!isErased[i]) prime.push_back(i);
    }
    for(int i=0; i<N; ++i){
        int now = v[i];
        for(int j=0; prime[j]*prime[j]<=now; ++j){
            int cnt=0;
            while(now%prime[j]==0){
                cnt++;
                now/=prime[j];
            }
            factorization[i].push_back({j,cnt});
            temp[j]+=cnt;
        }
        if(now!=1){
            int idx = lower_bound(prime.begin(), prime.end(), now) - prime.begin();
            factorization[i].push_back({idx,1});
            temp[idx]+=1;
        }
    }
    int res=1;
    for(int i=0; i<80000; ++i){
        if(temp[i]>=3){
            resFactor.push_back({i,temp[i]/N});
            res*=pow(prime[i],temp[i]/N);
        }
    }
    cout << res << ' ';
    int rescnt=0;
    for(int i=0; i<N; ++i){
        int j=0;
        for(auto [idx,cnt]:resFactor){
            bool flag=false;
            for(;j<factorization[i].size(); ++j){
                if(idx==factorization[i][j].first) {
                    flag=true;
                    rescnt+=max(0,cnt-factorization[i][j].second);
                    j++;
                    break;
                }
                else if(idx<factorization[i][j].first){
                    break;
                }
            }
            if(!flag) rescnt+=cnt;
        }
    }
    cout << rescnt << '\n';
}