#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x, y;
    Point(int x, int y):x(x),y(y){}
};
vector<Point> v;
void init(){
    v.clear();
}
int ccw(Point a, Point b, Point c){
    long long k = (long long)a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x;
    if(k>0) return 1;
    if(k==0) return 0;
    return -1;
}
int dist(Point a, Point b){
    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        init();
        int N; cin>>N;
        for(int i=0; i<N; ++i){
            int x,y; cin>>x>>y;
            v.push_back({x,y});
        }
        sort(v.begin(), v.end(), [](Point a, Point b){
            if(a.y==b.y) return a.x>b.x;
            return a.y < b.y;
        });
        int flag=true;
        for(int i=2; i<v.size(); ++i){
            if(ccw(v[0], v[1], v[i])!=0){
                flag=false;
                break;
            }
        }
        if(flag){
            cout << "2\n";
            cout << v.back().x << ' ' << v.back().y << '\n';
            cout << v[0].x << ' ' << v[0].y << '\n';
            continue;
        }
        sort(v.begin() + 1, v.end(), [](Point a, Point b){
            int c = ccw(v[0], a, b);
            if(c==0) {
                return dist(v[0], a) < dist(v[0], b);
            }
            return c>0;
        });
        vector<Point> stk;
        for(auto cur:v){
            if(stk.size()<2){
                stk.push_back(cur);
                continue;
            }
            while(stk.size() >= 2){
                Point k2 = stk.back(); stk.pop_back();
                Point k1 = stk.back(); stk.push_back(k2);
                // k1 -> k2 -> cur
                // cout << "("<<k1.x<<", "<<k1.y<<") -> ("<<k2.x<<", "<<k2.y<<") -> ("<<cur.x<<", "<<cur.y<<")\n";
                if(ccw(k1, k2, cur)>0){
                    break;
                }
                else{
                    stk.pop_back();
                }
            }
            stk.push_back(cur);
        }
        int idx=0;
        for(int i=0; i<stk.size(); ++i){
            if(stk[i].y > stk[idx].y) idx=i;
            else if(stk[i].y == stk[idx].y && stk[i].x < stk[idx].x) idx=i;
        }
        cout << stk.size() << '\n';
        for(int i=0; i<stk.size(); ++i){
            auto cur = stk[(idx-i+stk.size())%stk.size()];
            cout << cur.x << ' ' << cur.y << '\n';
        }
    }
}