#include <bits/stdc++.h>
using namespace std;
string increment(string a){
    a.back()+=1;
    for(int i=a.size()-1; i>=0; --i){
        if(a[i]>'9') {
            a[i]='0';
            if(i==0){
                return "1"+a;
            }
            a[i-1]+=1;
        }
    }
    return a;
}
int main(){
    string str; cin>>str;
    string temp = "";
    for(int i=0; i<(str.size()+1)/2; ++i){
        temp+=str[i];
    }
    string t2=temp;
    for(int i=temp.size()-1; i>=0; --i){
        if(i==temp.size()-1 && str.size()%2) continue;
        t2+=temp[i];
    }
    if(t2<=str){
        bool isOdd = str.size()%2;
        t2=increment(temp);
        if(t2.size() != temp.size()){
            cout << "1";
            for(int i=0; i<str.size()-1; ++i) cout << "0";
            cout << "1\n";
            return 0;
        }
        string t3 = t2;
        for(int i=t2.size()-1; i>=0; --i){
            if(i==t2.size()-1 && isOdd){
                continue;
            }
            t3+=t2[i];
        }
        cout << t3 << '\n';
    }
    else {
        cout << t2 << '\n';
    }
}