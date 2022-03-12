#include <bits/stdc++.h>
using namespace std;
int D[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isLeap(int x){
    if(x%400==0) return true;
    if(x%100==0) return false;
    if(x%4==0) return true;
    return false;
}
int main(){
    cout << "hello world"<<'\n';
    int a,b,c; cin>>a>>b>>c;
    int d,e,f; cin>>d>>e>>f;
    int year=a, month=b, day=c;
    if(a+1000==d && b>=e && c>=f){
        cout << "gg\n";
    }
    if(a+1000<d){
        cout << "gg\n";
    }
    int cnt=0;
    while(1){
        if(year==d && month==e && day==f) break;
        
        if(day>D[month]){
            day=1;
            month++;
        }
        if(month>12){
            month=1;
            year++;
        }
        cnt++;
        day++;
    }
    cout << "D-"<<cnt<<'\n';
}