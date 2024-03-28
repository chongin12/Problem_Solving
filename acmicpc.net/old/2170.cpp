#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct point {
    int x, y;
};
vector<point> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; ++i){
        int a, b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), [](point a, point b){
        if(a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    });
    int tempx=v[0].x;
    int tempy=v[0].y;
    int res=0;
    for(int i=1; i<N; ++i){
        if(tempy < v[i].x) {
            res+=tempy - tempx;
            tempx=v[i].x;
            tempy=v[i].y;
        } else {
            tempy=max(tempy, v[i].y);
        }
    }
    res+=tempy-tempx;
    cout << res << '\n';
}