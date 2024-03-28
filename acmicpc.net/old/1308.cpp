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
    int a,b,c; cin>>a>>b>>c;
    int d,e,f; cin>>d>>e>>f;
    int year=a, month=b, day=c-1;
    int cnt=-1;
    while(1){
        cnt++;
        day++;
        if(day>D[month]){
            day=1;
            month++;
        }
        if(month>12){
            month=1;
            year++;
        }
        if(isLeap(year)) D[2]=29;
        else D[2]=28;
        if(year-1000==a && month==b && day==c){
            cout << "gg\n";
            return 0;
        }
        if(year==d && month==e && day==f) break;
        
        
    }
    cout << "D-"<<cnt<<'\n';
}