#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    int A=0, B=0;
    bool isTie = 0;
    for(int i=0; i<str.size(); i+=2){
        int score = str[i+1]-'0';
        if(str[i]=='A'){
            A+=score;
        } else {
            B+=score;
        }
        if(isTie){
            if(A>=B+2){
                cout << "A\n";
                return 0;
            } else if(B>=A+2) {
                cout << "B\n";
                return 0;
            }
        } else {
            if(A==B && B==10){
                isTie = 1;
            } else if(A>B && A>=11) {
                cout << "A\n";
                return 0;
            } else if(B>A && B>=11) {
                cout << "B\n";
                return 0;
            }
        }
    }
}