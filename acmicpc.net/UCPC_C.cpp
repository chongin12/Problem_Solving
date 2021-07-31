#include <iostream>
using namespace std;
int main(){
	cout << fixed;
	cout.precision(8);
	double a;
	double d, k;
	cin >> a >> d >> k;
	double fa = a;
	d /= 100;
	k /= 100;
	k += 1;
	double win = d;
	double res = 0;
	double defeat = 1-win; //누적
	res+=a*win;
	win *= k;
	a+=fa;
	while(1){
		cout << "a : " << a << ", defeat : " << defeat << ", win : " << win << ", res : " << res << '\n';
		if(win>=1){
			res+=a * defeat;
			break;
		}
		res+=a * defeat * win;
		defeat *= 1-win;
		win *= k;
		a += fa;
	}
	cout << res << '\n';
}