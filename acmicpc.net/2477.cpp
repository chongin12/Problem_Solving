#include <bits/stdc++.h>
using namespace std;
int main(){
    int K; cin>>K;
    vector<int> v;
    for(int i=0; i<6; ++i){

        int a; cin>>a; cin>>a; v.push_back(a);
    }
    for(int i=0; i<6; ++i){
        int a=v[(0+i)%6];
        int b=v[(1+i)%6];
        int c=v[(2+i)%6];
        int d=v[(3+i)%6];
        int e=v[(4+i)%6];
        int f=v[(5+i)%6];
        if(a==c+e && b==d+f){
            cout << (a*b-d*e)*K << '\n';
        }
    }
}