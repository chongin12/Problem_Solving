#include <bits/stdc++.h>
using namespace std;
bool sieve[101];
vector<int> prime;
bool visited[101];
int main(){
    int N,K; cin>>N>>K;
    for(int i=2; i<101; ++i){
        if(sieve[i]) continue;
        prime.push_back(i);
        for(int p=i*i; p<101; p+=i){
            sieve[p]=true;
        }
    }
    int cnt=0;
    for(int i=1; i<=N; ++i){
        int s=i;
        for(auto it:prime){
            if(it>K) break;
            while(s%it==0) s/=it;
        }
        if(s==1) cnt++;
    }
    cout << cnt << '\n';
}