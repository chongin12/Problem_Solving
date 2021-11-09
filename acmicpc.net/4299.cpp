#include <iostream>
using namespace std;
int main(){
    int a,b; cin>>a>>b;
	if(a<b || (a+b)%2!=0) {
		cout << -1 << '\n';
		return 0;
	}
	b=(a+b)/2;
	a=a-b;
    cout << (a>b?a:b) << " " << (a>b?b:a) << '\n';
}