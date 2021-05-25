#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[10];
int N, M;
void f(int s, int count, vector<int> v){
    if(count==0) return;
    else if(s>=N) return;
    vector<int> vv=v;
    vv.push_back(arr[s]);
    if(count==1) {
        for(auto it:vv) cout << it << " ";
        cout << '\n';
        return;
    }
    for(int i=s; i<N; ++i){
        f(i, count-1, vv);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    for(int i=0; i<N; ++i) f(i, M, vector<int>());
}