#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
string nums[10][5] = {
    {
        "###",
        "#.#",
        "#.#",
        "#.#",
        "###",
    },
    {
        "..#",
        "..#",
        "..#",
        "..#",
        "..#",
    },
    {
        "###",
        "..#",
        "###",
        "#..",
        "###",
    },
    {
        "###",
        "..#",
        "###",
        "..#",
        "###",
    },
    {
        "#.#",
        "#.#",
        "###",
        "..#",
        "..#",
    },
    {
        "###",
        "#..",
        "###",
        "..#",
        "###",
    },
    {
        "###",
        "#..",
        "###",
        "#.#",
        "###",
    },
    {
        "###",
        "..#",
        "..#",
        "..#",
        "..#",
    },
    {
        "###",
        "#.#",
        "###",
        "#.#",
        "###",
    },
    {
        "###",
        "#.#",
        "###",
        "..#",
        "###",
    },
};
int main(){
    int N; cin>>N;
    string str[5];
    for(int i=0; i<5; ++i){
        cin>>str[i];
    }
    vector<int> v[11];
    for(int i=0; i<N; ++i){
        for(int num=0; num<10; ++num){
            bool flag=true;
            for(int j=0; j<5; ++j){
                for(int k=0; k<3; ++k){
                    int x=j;
                    int y=4*i+k;
                    if(nums[num][j][k]=='.' && str[x][y]=='#') flag=false;
                }
            }
            if(flag) v[i].push_back(num);
        }
    }
    ll cnt=1;
    for(int i=0; i<N; ++i){
        cnt*=(ll)v[i].size();
    }
    double res=0;
    double k=1;
    for(int i=N-1; i>=0; --i, k*=10){
        for(auto it:v[i]){
            res+=(double)(cnt/(ll)v[i].size())*k*it;
        }
    }
    cout << fixed;
    cout.precision(6);
    if(cnt==0) cout << "-1\n";
    else cout << res/(double)cnt << '\n';
}