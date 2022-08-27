#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ifstream ifs("./second_hands_validation_input.txt");
    ofstream ofs("./A.txt");

    int T; ifs>>T;
    for(int t=1; t<=T; ++t){
        ofs << "Case #"<<t<<": ";
        int N,K; ifs>>N>>K;
        vector<int> v(N);
        for(int i=0; i<N; ++i){
            ifs>>v[i];
        }
        if(N%K && N/K>=2){
            ofs << "NO\n";
        }
        else {
            sort(v.begin(), v.end());
            bool flag=true;
            for(int i=2; i<v.size(); ++i){
                if(v[i-2]==v[i-1] && v[i-1]==v[i]){
                    flag=false;
                    break;
                }
            }
            if(flag) ofs << "YES\n";
            else ofs << "NO\n";
        }
    }
}