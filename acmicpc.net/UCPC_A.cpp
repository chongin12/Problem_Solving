#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int start=-1, End=-1, a, b;
int jari(int n){
	if(n/1000>0) return 4;
	else if(n/100>0) return 3;
	else if(n/10>0) return 2;
	return 1;
}
int main(){
	string str; cin >> str;
	a = str[0] - '0';
	if(str.length() == 1){
		cout << a << " " << a << '\n';
		return 0;
	}
	if(a==9){
		b = (str[1]-'0') * 10 + (str[2]-'0');
	} else {
		b = (str[1]-'0');
	}
	if(a+1==b) {
		start = a;
	}

	if(start==-1){
		a = (str[0]-'0')*10 + (str[1]-'0');
		if(str.length() == 2){
			cout << a << " " << a << '\n';
			return 0;
		}
		if(a==99){
			b = (str[2]-'0') * 100 + (str[3]-'0') * 10 + (str[4]-'0');
		} else {
			b = (str[2]-'0') * 10 + (str[3]-'0');
		}

		if(a+1==b) {
			start = a;
		}
		
	}

	if(start==-1) {
		a = (str[0]-'0')*100 + (str[1]-'0')*10 + (str[2]-'0');
		if(str.length() == 3) {
			cout << a << " " << a << '\n';
			return 0;
		}
		//b = (str[3]-'0') * 100 + (str[4]-'0') * 10 + (str[5]-'0');
		start = a;
	}
	End=start;
	int i=0;
	for(; i<str.length(); i+=jari(End), End+=1){}
	End-=1;
	cout << start << " " << End << '\n';
	return 0;
}