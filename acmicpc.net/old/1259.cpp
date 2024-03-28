#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    while(1){
        cin >> str;
        if(str=="0") break;
        int left=0, right=str.length()-1;
        bool pass=true;
        while(left<=right){
            if(str[left] != str[right]) {
                pass=false;
                break;
            }
            left+=1;
            right-=1;
        }
        if(pass) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
}