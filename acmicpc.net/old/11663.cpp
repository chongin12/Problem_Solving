#include <iostream>
#include <algorithm>
using namespace std;
int dot[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i=0; i<N; ++i){
        cin >> dot[i];
    }
    sort(dot, dot+N);
    while(M--){
        int a, b; cin >> a >> b;
        int t1 = lower_bound(dot, dot+N, a) - dot;
        int t2 = upper_bound(dot, dot+N, b) - dot;
        cout << t2-t1<< '\n';
    }
}