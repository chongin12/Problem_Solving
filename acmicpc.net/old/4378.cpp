#include <bits/stdc++.h>
using namespace std;
string str="=-0987654321`\\][POIUYTREWQ';LKJHGFDSA/.,MNBVCXZ  ";
int main(){
    while(1){
        string k;
        getline(cin, k);
        if(k.size()==0) break;
        for(auto it:k){
            for(int i=0; i<str.size(); ++i){
                if(str[i]==it){
                    cout << str[i+1];
                    break;
                }
            }
        }
        cout << '\n';
    }
}