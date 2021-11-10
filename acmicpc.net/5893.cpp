#include <bits/stdc++.h>
using namespace std;
int main(){
	string a; cin>>a;
	string b=a+"0000";
	int c=0;
	for(int i=a.size()-1; i>=0; --i){
		if(a[i]=='1'&&b[i+4]=='1'){
			if(c==0){
				c=1;
				b[i+4]='0';
			}
			else{
				c=1;
				b[i+4]='1';
			}
		}
		else if(a[i]=='0'&&b[i+4]=='0'){
			if(c==1){
				c=0;
				b[i+4]='1';
			} 
		}
		else{
			if(c==1){
				c=1;
				b[i+4]='0';
			}
			else{
				c=0;
				b[i+4]='1';
			}
		}
	}
	for(int i=3; i>=0; --i){
		if(c==1 && b[i]=='1'){
			b[i]='0';
		}
		else if(c==1 && b[i]=='0'){
			b[i]='1';
			c=0;
		}
	}
	if(c==1) b="1"+b;
	cout << b << '\n';
}