#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
struct point {
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}
    bool operator<(const point &a) const {
        if(y==a.y) return x < a.x;
        else return y < a.y; // y기준 정렬
    }
};
vector<point> vx;
set<point> s;
int dist(point a, point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; ++i){
        int a, b; cin >> a >> b;
        vx.push_back({a,b});
    }
    sort(vx.begin(), vx.end(), [](point a, point b){
        if(a.x==b.x) return a.y<b.y;
        else return a.x<b.x;
    });
    s.insert(vx[0]);
    s.insert(vx[1]);
    int D = dist(vx[0], vx[1]);
    int start=0;
    for(int i=2; i<n; ++i){
        while(start < i) {
            int xDif = vx[i].x-vx[start].x;
            if(xDif*xDif > D) {
                s.erase(vx[start]);
                start++;
            } else {
                break;
            }
        }
        int sqrtD=sqrt(D);
        auto low = s.lower_bound(point({-100000, vx[i].y-sqrtD}));
        auto high = s.upper_bound(point({100000, vx[i].y+sqrtD}));
        for(auto it=low; it!=high; ++it){
            int tempD=dist(vx[i], *it);
            if(tempD < D) D=tempD;
        }
        s.insert(vx[i]);
    }
    cout << D << '\n';
}