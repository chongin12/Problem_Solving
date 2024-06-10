#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct Node {
    ll ch;
    ll N;
};
deque<Node> dq;
ll priority(ll ch){
    if(ch=='+') return 1;
    else if(ch=='-') return 1;
    else if(ch=='*') return 0;
    else return 0;
}
ll calc(Node a, Node ch, Node b){
    if(ch.N=='+') return a.N+b.N;
    else if(ch.N=='-') return a.N-b.N;
    else if(ch.N=='*') return a.N*b.N;
    else return a.N/b.N;
}
int main(){
    string str; cin>>str;
    bool frontMinus=false;
    if(str[0]=='-'){
        frontMinus=true;
        reverse(str.begin(), str.end());
        str.pop_back();
        reverse(str.begin(), str.end());
    }
    ll temp=0;
    for(auto it:str){
        if(it>='0' && it<='9') temp=temp*10+it-'0';
        else {
            dq.push_back({0,temp});
            temp=0;
            dq.push_back({1,it});
        }
    }

    dq.push_back({0,temp});
    if(frontMinus) dq[0].N*=-1;
    while(dq.size()>1){
        ll a = calc(dq[0], dq[1], dq[2]);
        ll b = calc(dq[dq.size()-3], dq[dq.size()-2], dq[dq.size()-1]);
        if(priority(dq[1].N) < priority(dq[dq.size()-2].N)) {
            dq.pop_front();
            dq.pop_front();
            dq.pop_front();
            dq.push_front({0,a});
        }
        else if(priority(dq[1].N) > priority(dq[dq.size()-2].N)) {
            dq.pop_back();
            dq.pop_back();
            dq.pop_back();
            dq.push_back({0,b});
        }
        else if(a>=b){
            dq.pop_front();
            dq.pop_front();
            dq.pop_front();
            dq.push_front({0,a});
        }
        else{
            dq.pop_back();
            dq.pop_back();
            dq.pop_back();
            dq.push_back({0,b});
        }
    }
    cout << dq[0].N << '\n';
}