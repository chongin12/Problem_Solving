#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream ifs("./second_friend_input.txt");
    ofstream ofs("./B.txt");
    int T; ifs>>T;
    for(int t=1; t<=T; ++t){
        ofs << "Case #"<<t<<": ";
        int R,C; ifs>>R>>C;
        bool isTree=false;
        for(int i=0; i<R; ++i){
            string str; ifs>>str;
            for(int j=0; j<str.size(); ++j){
                if(str[j]=='^') isTree=true;
            }
        }
        if(!isTree){
            ofs << "Possible\n";
            for(int i=0; i<R; ++i){
                for(int j=0; j<C; ++j){
                    ofs << ".";
                }
                ofs << '\n';
            }
        }
        else if(isTree && (R==1 || C==1)){
            ofs << "Impossible\n";
        }
        else{
            ofs << "Possible\n";
            for(int i=0; i<R; ++i){
                for(int j=0; j<C; ++j){
                    ofs << "^";
                }
                ofs << '\n';
            }
        }
    }
}