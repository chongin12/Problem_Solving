#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        string str; cin>>str;
        if(cin.eof()) break;
        vector<int> v;
        for(int i=0; i<str.size(); ++i) v.push_back(i);
        int N; cin>>N;
        cout << str << " " << N << " = ";
        bool pass=true;
        for(int i=0; i<N-1; ++i){
            if(!next_permutation(v.begin(), v.end())){
                pass=false;
                break;
            }
        }
        if(pass){
            for(auto it:v){
                cout << str[it];
            }
            cout << '\n';
        } else {
            cout << "No permutation\n";
        }
    }
}