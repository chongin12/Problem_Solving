#include <bits/stdc++.h>
using namespace std;
vector<int> v;
struct node{
    vector<int> arr;
    int w, t, prev;
    node(vector<int> arr, int w, int t, int prev):arr(arr), w(w), t(t), prev(prev){}
};
int main(){
    int N, W, T, K; cin>>N>>W>>T>>K;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    queue<node> q;
    q.push(node(v, W, 0, -1));
    int res=0;
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        cur.t++;
        //1. 화력 감소
        int near[10]={};
        for(int i=0; i<cur.arr.size(); ++i){
            if(cur.arr[i]){
                if(i) near[i-1]++;
                near[i+1]++;
            }
        }
        int modak=0;
        for(int i=0; i<cur.arr.size(); ++i){
            if(cur.arr[i] && i!=cur.prev){
                cur.arr[i]=max(0, cur.arr[i]-(3-near[i]));
            }
            if(cur.arr[i]>0) modak++;
        }
        // cout << "now t : " << cur.t << '\n';
        // for(auto it:cur.arr) cout << it << ' ';
        // cout << "\ncur.w : " << cur.w << ", cur.prev : " << cur.prev << '\n';
        //2. 장작 넣기 or 놀이 종료
        if(modak<K) continue;
        if(cur.t==T) {
            res+=1;
            continue;
        }
        if(cur.w!=0) q.push(node(cur.arr, cur.w-1, cur.t, cur.w-1));
        q.push(node(cur.arr, cur.w, cur.t, cur.w));
        if(cur.w!=N-1) q.push(node(cur.arr, cur.w+1, cur.t, cur.w+1));
    }
    cout << res << '\n';
}