#include <cmath>
#include <iostream>
typedef long long int ll;
using namespace std;
int main(){
    ll min, max;
    cin >> min >> max;
    ll a=sqrt(min-1);
    ll b=sqrt(max);
    cout << max-min+1-(b-a);
}
