#include <bits/stdc++.h>
#define PI M_PI
#define x first
#define y second

using namespace std;
using pll = pair<long long, long long>;
// using pdd =pair<double, double>;
using ll = long long;
using Point=pair<ll,ll>;

int N;
pll rad[10001];
pair<pll, pll> l[10001];
pll p1, p2;

int CCW(const Point &p1, const Point &p2, const Point &p3){
	ll t=(p2.x-p1.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p2.y-p1.y);
	if(t>0) return 1;
	if(t<0) return -1;
	return 0;
}
bool Cross(Point a, Point b, Point c, Point d){
	int ab = CCW(a, b, c) * CCW(a, b, d);
	int cd = CCW(c, d, a) * CCW(c, d, b);
	if(ab==0 && cd==0){
		if(a>b) swap(a,b);
		if(c>d) swap(c,d);
		return !(b<c||d<a);
	}
	return ab<=0 && cd<=0;
}

pll get_pos(double angle, double radius)
{
    double x1 = radius * cos(angle / 10.0 * (PI / 180.0));
    double y1 = radius * sin(angle / 10.0 * (PI / 180.0));

    return make_pair(x1*1000, y1*1000);
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> rad[i].first >> rad[i].second;
    }
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;

    p1 = get_pos(p1.first, p1.second);
    p2 = get_pos(p2.first, p2.second);
    pair<pll, pll> p = {p1, p2};
    // cout << p1.first << ", "<<p1.second << ", "<<p2.first << ", "<<p2.second << '\n';
   
    for(int i = 0; i < N; i++)
    {
        pll p1 = get_pos(rad[i].first, 1000);
        pll p2 = get_pos(rad[i].second, 1000);

        l[i] = {p1, p2};

        // cout << p1.first << ", "<<p1.second << ", "<<p2.first << ", "<<p2.second << '\n';
    }

    int ans = 0;
    for(int i = 0; i < N ;++i)
    {
        Point p1 = l[i].first;
        Point p2 = l[i].second;

        if(Cross(p1, p2, p.first, p.second))
            ans++;
    }

    if(ans % 2 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";


}