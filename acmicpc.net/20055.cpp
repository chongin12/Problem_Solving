#include <bits/stdc++.h>
using namespace std;
struct Node {
    int negu, isRobot;
};
int N, K;
vector<Node> v;
void f() {
    Node temp = v[N*2-1];
    for(int i=N*2-1; i>0; --i){
        v[i]=v[i-1];
    }
    v[0]=temp;
    v[N-1].isRobot = 0;
    for(int i=N-2; i>=0; --i){
        if(v[i].isRobot && !v[i+1].isRobot && v[i+1].negu>0){
            v[i].isRobot=0;
            v[i+1].isRobot=1;
            v[i+1].negu--;
        }
    }
    v[N-1].isRobot=0;
    if(v[0].negu>0) v[0].isRobot=1, v[0].negu--;
}
int main(){
    cin>>N>>K;
    int res=0;
    for(int i=0; i<N*2; ++i){
        int a; cin>>a;
        v.push_back({a,0});
    }
    while(1){
        res++;
        f();
        int cnt=0;
        for(int i=0; i<N*2; ++i){
            // cout << "("<<v[i].negu<<", " <<v[i].isRobot<<")\n";
            if(v[i].negu==0) cnt++;
        }
        if(cnt>=K) break;
    }
    cout << res << '\n';
}