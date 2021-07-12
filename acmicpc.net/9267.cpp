#include <bits/stdc++.h>
using namespace std;
using ll=__int128;
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
struct node {
    ll R, X, Y;
    node(ll R, ll X, ll Y) : R(R), X(X), Y(Y) {}
};
/*
node EEU2(ll a, ll b){ // a와 b를 넣으면 gcd(a,b)=aX+bY 에서 {gcd(a,b), X, Y} 리턴.
    ll r, r1, r2, x, x1, x2, y, y1, y2, q;
    r1=a, r2=b;
    x1=1, x2=0;
    y1=0, y2=1;

    while(r2>0) {
        q = r1 / r2;
        r = r1-r2*q;
        r1=r2, r2=r;

        x = x1-x2*q;
        x1=x2, x2=x;

        y = y1-y2*q;
        y1=y2, y2=y;

        //printf("r1 : %lld, r2 : %lld, x1 : %lld, x2 : %lld, y1 : %lld, y2 : %lld\n", r1, r2, x1, x2, y1, y2);
    }//r1이 gcd(a,b), r1=a*x1+b*y1을 만족.
    return node(r1, x1, y1);
}
*/
node EEU(ll a, ll b) {
    if(b==0) return node(a, 1, 0);
    node temp = EEU(b, a%b);
    return node(temp.R, temp.Y, temp.X-(a/b)*temp.Y);
}

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    ll a, b, s; 
    //cin >> a >> b >> s;
    a = read(); b = read(); s = read();
    
    //1. s가 a*X+b*Y꼴로 만들어질 수 있는 수인지 검사.
    //2. X와 Y의 최대공약수가 1이고, x와y가 양수인지 검사. 확장 유클리드 알고리즘 사용.

    //1
    if(a==0 && b==0) {
        if(s==0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        return 0;
    }
    else if(a==0) {
        if(s % b == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        return 0;
    }
    else if(b==0) {
        if(s % a == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        return 0;
    }
    ll g = gcd(a, b);
    if(s%g) {
        cout << "NO" << '\n';
        return 0;
    }
    node temp = EEU(a/g, b/g);
    temp.X *= s/g;
    temp.Y *= s/g;
    /*
    cout << "temp.X : " << temp.X << ", temp.Y : " << temp.Y << '\n';
    if(temp.X < 0 || temp.Y < 0) {
        cout << "NO2" << '\n';
        return 0;
    }
    */
    for(ll i=-g*temp.X/b-1; i<=g*temp.Y/a+1; i=i+1) {// 정수해를 찾는 과정. 
        if(gcd(temp.X + i*b/g, temp.Y - i*a/g)==1) {
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
/*
    node temp2 = EEU(temp.X, temp.Y);
    cout << "temp2.X : " << temp2.X << ", temp2.Y : " << temp2.Y << '\n';
    if(temp2.R==1 && temp2.X >= 0 && temp2.Y >= 0){
        cout << "YES" << '\n';
    }
    else {
        cout << "NO3" << '\n';
    }
    */
}