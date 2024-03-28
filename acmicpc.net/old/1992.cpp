#include <bits/stdc++.h>
using namespace std;
string arr[66];
string f(int x, int y, int size){
    if(size==1) return string()+""+arr[x][y];
    bool flag=true;
    string temp1 = f(x,y,size/2);
    string temp2 = f(x,y+size/2,size/2);
    string temp3 = f(x+size/2,y,size/2);
    string temp4 = f(x+size/2,y+size/2,size/2);
    if(temp1.size()==1 && temp1==temp2 && temp2==temp3 && temp3==temp4){
        return temp1;
    }
    return "("+ temp1 + temp2 + temp3 + temp4 +")";
}
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    cout << f(0,0,N) << '\n';
}