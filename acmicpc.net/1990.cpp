#include <bits/stdc++.h>
using namespace std;
string pre, post;
vector<int> pel[9];
vector<int> prime;
int isErased[10001];
bool f(int x){
    bool ret=true;
    for(int i=0; prime[i]*prime[i]<=x; i++){
        if(x%prime[i]==0){
            ret = false;
            break;
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=2; i<10001; ++i){
        if(!isErased[i]){
            prime.push_back(i);
            for(int j=i*i; j<10001; j+=i){
                isErased[j]=1;
            }
        }
    }
    int a, b; cin>>a>>b;
    for(int i=0; i<10; ++i){
        pel[1].push_back(i);
        pel[2].push_back(i*11);
    }
    int offset=100;
    for(int i=3; i<9; ++i){
        for(auto it:pel[i-2]){
            for(int j=0; j<10; ++j){
                pel[i].push_back(it*10+(offset+1)*j);
            }
        }
        offset*=10;
    }
    offset=1;
    vector<int> res;
    for(int i=1; i<9; ++i){
        for(auto it:pel[i]){
            if(it<offset) continue;
            if(it<a || it>b) continue;
            if(f(it)) res.push_back(it);
        }
        offset *= 10;
    }
    sort(res.begin(), res.end());
    for(auto it:res){
        cout << it << '\n';
    }
    cout << "-1\n";
}