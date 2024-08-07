#include <bits/stdc++.h>
using namespace std;
const int MN = 1000001;
bool isErased[MN];
vector<int> primes;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=2; i*i<MN; ++i){
        if(isErased[i]) continue;
        for(int j=i*i; j<MN; j+=i) isErased[j]=true;
    }
    for(int i=3; i<MN; i+=10) {
        if(!isErased[i]) primes.push_back(i);
    }
    while(1){
        int a; cin>>a;
        int oria=a;
        if(a==-1) break;
        bool flag=true;
        for(auto it:primes){
            while(a%it==0){
                a/=it;
            }
            if(a==1) break;
            if(a<it) {
                flag=false;
                break;
            }
        }
        cout << oria << " " << (!flag ? "NO" : "YES") << '\n';
    }
}