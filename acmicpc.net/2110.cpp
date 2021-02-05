#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int f(int dist){
    int cnt=1;
    int prev=v[0];
    for(int i=1; i<v.size(); ++i){
        if(v[i]-prev >= dist) {
            prev=v[i];
            cnt++;
        }
    }
    return cnt;
}
int main(){
    int N, C; cin >> N >> C;
    v.assign(N, 0);
    for(int i=0; i<N; ++i){
        cin >> v[i];
    } 
    sort(v.begin(), v.end());
    int left=0, right=1e9+1;
    while(left+1<right){
       // cout << "left : " << left << ", right : " << right << '\n';
        int mid=(left+right)/2;
        if(f(mid)>=C) left=mid;
        else right=mid;
    }
    cout << left << '\n';
}