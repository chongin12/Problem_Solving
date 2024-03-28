#include <bits/stdc++.h>
using namespace std;
string m[13]={"","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int md[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    string a,b,c,d; cin>>a>>b>>c>>d;
    double k=0;
    if(atoi(c.c_str())%400==0) md[2]=29;
    else if(atoi(c.c_str())%100==0) md[2]=28;
    else if(atoi(c.c_str())%4==0) md[2]=29;
    for(int i=1; i<=12; ++i){
        if(a==m[i]) {
            for(int j=0; j<i; ++j){
                k+=md[j]*24*60;
            }
        }
    }
    k+=((b[0]-'0')*10+(b[1]-'0')-1)*24*60;
    k+=((d[0]-'0')*10+(d[1]-'0'))*60;
    k+=(d[3]-'0')*10+(d[4]-'0');
    cout << fixed;
    cout.precision(10);
    cout << k * 100 / ((337+md[2])*24*60) << '\n';
}