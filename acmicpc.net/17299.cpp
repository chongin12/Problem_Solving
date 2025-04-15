#include <bits/stdc++.h>
using namespace std;
int cnt[1000001];
int arr[1000001];
int res[1000001];
struct Node {
    int index, count;
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        cin>>arr[i];
        cnt[arr[i]]++;
    }
    vector<Node> s;
    for(int i=1; i<=N; ++i){
        Node a={i,cnt[arr[i]]};
        while(!s.empty()){
            auto cur = s.back();
            if(cur.count < a.count){
                res[cur.index]=arr[i];
                s.pop_back();
            }
            else break;
        }
        s.push_back(a);
    }
    for(int i=1; i<=N; ++i){
        if(res[i]==0) cout << "-1 ";
        else cout << res[i] << " ";
    }
    cout << '\n';
}