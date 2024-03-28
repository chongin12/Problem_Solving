#include <iostream>
#include <vector>
using namespace std;
int main(){
    int T; std::cin>>T;
    while(T--){
        vector<int> v(26);
        int res=0;
        string st; cin>>st;
        for(auto it:st){
            v[it-'A']++;
        }
        for(int i=0; i<v.size(); ++i){
            if(!v[i]) res+=65+i;
        }
        cout << res << '\n';
    }
}