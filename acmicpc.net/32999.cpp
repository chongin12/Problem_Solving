#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int f(int start, int end){
    if(start==end){
        return 1;
    }
    int ret=1;
    int minValue = 987654321;
    for(int i=start; i<=end; ++i){
        minValue=min(minValue, v[i]);
    }
    int l=start;
    for(int i=start; i<=end; ++i){
        if(v[i]==minValue){
            if(l!=i) {
                ret+=f(l, i-1);
            }
            l=i+1;
        }
    }
    if(l!=end+1) ret+=f(l, end);
    // cout << start << "~" << end << " : " << ret << '\n';
    return ret;
}
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    cout << f(0, N-1) << '\n';
}