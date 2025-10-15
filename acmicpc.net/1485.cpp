#include <bits/stdc++.h>
using namespace std;
int dist(int x1, int y1, int x2, int y2){
    return (y2-y1)*(y2-y1)+(x2-x1)*(x2-x1);
}
int main(){
    int T; cin>>T;
    while(T--){
        vector<int> x, y;
        for(int i=0; i<4; ++i){
            int a, b; cin>>a>>b;
            x.push_back(a);
            y.push_back(b);
        }
        bool flag=true;
        for(int i=0; i<4; ++i){
            vector<int> cand;
            for(int j=0; j<4; ++j){
                if(i==j) continue;
                cand.push_back(dist(x[i], y[i], x[j], y[j]));
            }
            sort(cand.begin(), cand.end());
            if(cand[0]!=cand[1] || cand[0]+cand[1]!=cand[2]) flag=false;
        }
        cout << flag << '\n';
    }
}
// a, a, sqrt(a*a+a*a)