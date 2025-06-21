#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
priority_queue<pii> pq;
int arr[10001];
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int d, p; cin>>p>>d;
        pq.push({p,d});
    }
    while(!pq.empty()){
        auto cur=pq.top(); pq.pop();
        for(int i=cur.second; i>=1; --i){
            if(arr[i]==0){
                arr[i]=cur.first;
                break;
            }
        }
    }
    int res=0;
    for(int i=1; i<=10001; ++i){
        res+=arr[i];
    }
    cout << res << '\n';
}

/*
7
100 2
50 10
20 1
10 3
8 2
5 20
2 1
*/