#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    int r=0;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        vector<int> v;
        for(auto it:str){
            if(v.size() && v.back()==it-'A') v.pop_back();
            else v.push_back(it-'A');
        }
        if(v.size()==0) r++;
    }
    cout << r << '\n';
}