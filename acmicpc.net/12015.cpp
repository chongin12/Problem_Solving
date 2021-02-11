#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    vector<int> v;
    for(int i=0; i<N; ++i){
        int t; cin >> t;
        if(i==0) v.push_back(t);
        else {
            auto it = lower_bound(v.begin(), v.end(), t) - v.begin();
            //cout << "now : " << t << ", it : " << it << '\n';
            //for(auto itt:v) cout << itt << " ";
            //cout << '\n';
            if(v.size()==it) v.push_back(t);
            
            else if(v[it]>t) v[it]=t;
        }
    }
    cout << v.size() << '\n';
}