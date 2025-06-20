#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    if(N==1){
        cout << "A\n";
        return 0;
    } else if(N==2){
        if(v[0]!=v[1]) cout << "A\n";
        else cout << v[1] << "\n";
        return 0;
    }

    int a,b;
    if(v[1]==v[0]) {
        if(v[1]==v[2]){
            a=0;
        }
        else{
            cout << "B\n";
            return 0;
        }
    }
    else if(v[1]==v[2]){
        a=0;
    }
    else if((v[2]-v[1])%(v[1]-v[0])!=0){
        cout << "B\n";
        return 0;
    } else {
        a=(v[2]-v[1])/(v[1]-v[0]);
    }
    b=v[1]-v[0]*a;

    for(int i=3; i<N; ++i){
        if(v[i]!=v[i-1]*a+b){
            cout << "B\n";
            return 0;
        }
    }
    cout << v.back() * a + b << '\n';
}