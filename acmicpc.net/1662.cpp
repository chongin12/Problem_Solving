#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;
int main(){
    string str; cin>>str;
    vector<ll> v; // -xx : -(문자열 개수+1)
    str="1("+str+")";
    for(auto it:str){
        if(it=='('){
            v.push_back(INF);
        }
        else if(it==')'){
            ll cnt=0;
            while(v.back()!=INF){
                if(v.back()<0){
                    cnt+=-v.back()-1;
                }
                else{
                    cnt+=1;
                }
                v.pop_back();
            }
            v.pop_back();
            if(v.back()>=0){
                cnt*=v.back();
                v.pop_back();
            }
            v.push_back(-(cnt+1));
        }
        else{
            v.push_back(it-'0');
        }
    }
    cout << -(v[0])-1 << '\n';
}