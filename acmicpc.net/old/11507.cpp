#include <bits/stdc++.h>
using namespace std;
int P[14],K[14],H[14],T[14];
int p,k,h,t;
int main(){
    string str; cin>>str;
    for(int i=0; i<str.size(); i+=3){
        int num = (str[i+1]-'0')*10+str[i+2]-'0';
        if(str[i]=='P'){
            p++;
            P[num]++;
            if(P[num]>1){
                cout << "GRESKA\n";
                return 0;
            }
        }
        else if(str[i]=='K'){
            k++;
            K[num]++;
            if(K[num]>1){
                cout << "GRESKA\n";
                return 0;
            }
        }
        else if(str[i]=='H'){
            h++;
            H[num]++;
            if(H[num]>1){
                cout << "GRESKA\n";
                return 0;
            }
        }
        else{
            t++;
            T[num]++;
            if(T[num]>1){
                cout << "GRESKA\n";
                return 0;
            }
        }
    }
    cout << 13-p << " " << 13-k << " " << 13-h << " " << 13-t << '\n';
}