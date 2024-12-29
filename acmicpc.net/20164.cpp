#include <bits/stdc++.h>
using namespace std;
int minf(int x) { // x로 시작하는 최솟값
    int ret=0;
    if(x<10){
        if(x%2) ret++;
    }
    else if(x<100) {
        int a=x/10, b=x%10;
        ret+=a%2+b%2;
        ret+=minf(a+b);
    }
    else {
        string s = to_string(x);
        int count = s.size()-1;
        for(auto it:s){
            ret+=(it-'0')%2;
        }
        int temp=987654321;
        for(int i=0; i<count-1; ++i){
            for(int j=i+1; j<count; ++j){
                int a=0,b=0,c=0;
                for(int k=0; k<=i; ++k){
                    a=a*10+(int)(s[k]-'0');
                }
                for(int k=i+1; k<=j; ++k){
                    b=b*10+(int)(s[k]-'0');
                }
                for(int k=j+1; k<s.size(); ++k){
                    c=c*10+(int)(s[k]-'0');
                }
                temp=min(temp,minf(a+b+c));
            }
        }
        ret+=temp;
    }
    return ret;
}
int maxf(int x){ // x로 시작하는 최대값
    int ret=0;
    if(x<10){
        if(x%2) ret++;
    }
    else if(x<100) {
        int a=x/10, b=x%10;
        ret+=a%2+b%2;
        ret+=maxf(a+b);
    }
    else {
        string s = to_string(x);
        int count = s.size()-1;
        for(auto it:s){
            ret+=(it-'0')%2;
        }
        int temp=0;
        for(int i=0; i<count-1; ++i){
            for(int j=i+1; j<count; ++j){
                int a=0,b=0,c=0;
                for(int k=0; k<=i; ++k){
                    a=a*10+(int)(s[k]-'0');
                }
                for(int k=i+1; k<=j; ++k){
                    b=b*10+(int)(s[k]-'0');
                }
                for(int k=j+1; k<s.size(); ++k){
                    c=c*10+(int)(s[k]-'0');
                }
                temp=max(temp,maxf(a+b+c));
            }
        }
        ret+=temp;
    }
    return ret;
}
int main(){
    int N; cin>>N;
    cout << minf(N) << " " << maxf(N) << '\n';
}