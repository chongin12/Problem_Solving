#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int main(){
	string x;cin>>x;
	for(int i=0; i<x.size(); ++i){
		arr[i]=x[i]-'0';
	}
	int d=arr[1]-arr[0];
	if(d<=0 || arr[x.size()-1]-arr[x.size()-2]>=0) {
		cout << "NON ALPSOO\n";
		return 0;
	}
	for(int i=2; i<x.size(); ++i){
		if(arr[i-1]+d!=arr[i]){
			if((arr[i]-arr[i-1])*d<0){
				d=arr[i]-arr[i-1];
				continue;
			}
			else{
				cout << "NON ALPSOO\n";
				return 0;
			}
		}
		if(arr[i-1]==arr[i]){
			cout << "NON ALPSOO\n";
			return 0;
		}
	}
	cout << "ALPSOO\n";
}