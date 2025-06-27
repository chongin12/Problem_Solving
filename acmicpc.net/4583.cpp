#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        string str; cin>>str;
        if(str=="#"){
            break;
        }
        string res="";
        bool flag=true;
        while(!str.empty()){
            if(str.back()=='b'){
                res+="d";
            }
            else if(str.back()=='d'){
                res+="b";
            }
            else if(str.back()=='p'){
                res+="q";
            }
            else if(str.back()=='q'){
                res+="p";
            }
            else if(str.back()=='i'){
                res+="i";
            }
            else if(str.back()=='o'){
                res+="o";
            }
            else if(str.back()=='v'){
                res+="v";
            }
            else if(str.back()=='w'){
                res+="w";
            }
            else if(str.back()=='x'){
                res+="x";
            }
            else {
                cout << "INVALID\n";
                flag=false;
                break;
            }
            str.pop_back();
        }
        if(flag)
            cout << res << '\n';
    }
}