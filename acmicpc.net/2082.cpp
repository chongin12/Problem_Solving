#include <bits/stdc++.h>
using namespace std;
vector<string> v;
string arr[][5] = {
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
    }
};
int main(){
    string str;
    string res="";
    getline(cin, str); v.push_back(str);
    getline(cin, str); v.push_back(str);
    getline(cin, str); v.push_back(str);
    getline(cin, str); v.push_back(str);
    getline(cin, str); v.push_back(str);
    for(int i=0; i<4; ++i){
        for(int w=0; w<9; ++w){
            bool flag=true;
            for(int j=0; j<5; ++j){
                for(int k=0; k<3; ++k){
                    if(v[j][i*4+k]=='#' && arr[w][j][k]=='.'){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                res+=(char)(w+'0');
                break;
            }
        }
    }
    cout << res[0] << res[1] << ":" << res[2] << res[3] << '\n';
}