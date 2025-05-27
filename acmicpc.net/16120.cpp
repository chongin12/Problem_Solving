#include <bits/stdc++.h>
using namespace std;
string str;
int main(){
    cin>>str;
    vector<int> v;
    for(auto it:str){
        if(it=='P') {
            v.push_back(1);

            int n=v.size();
            if(n>=4){
                if(v[n-1]==1 && v[n-2]==0 && v[n-3]==1 && v[n-4]==1){
                    v.pop_back();
                    v.pop_back();
                    v.pop_back();
                }
            }
        }
        else v.push_back(0);
    }
    if(v.size()==1 && v[0]==1) cout << "PPAP\n";
    else cout << "NP\n";
}