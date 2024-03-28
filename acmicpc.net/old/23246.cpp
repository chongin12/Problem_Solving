#include <bits/stdc++.h>
using namespace std;
struct node{
    int b,mul,sum;
    node(int b, int mul, int sum):b(b),mul(mul),sum(sum){}
};
int main(){
    int n; cin>>n;
    vector<node> v;
    for(int i=0; i<n; ++i){
        int b,p,q,r; cin>>b>>p>>q>>r;
        v.push_back(node(b,p*q*r,p+q+r));
    }
    sort(v.begin(), v.end(), [](node a, node b){
        if(a.mul==b.mul){
            if(a.sum==b.sum){
                return a.b<b.b;
            }
            return a.sum<b.sum;
        }
        return a.mul<b.mul;
    });
    cout << v[0].b << " " << v[1].b << " " << v[2].b << '\n';
}