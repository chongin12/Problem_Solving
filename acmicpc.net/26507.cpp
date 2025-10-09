#include <bits/stdc++.h>
using namespace std;
int arr[100][10][10];
int temp[10][10];
void init(){
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            temp[i][j]=0;
        }
    }
}
void f(int idx){
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            temp[i][j]+=arr[idx][i][j];
        }
    }
}
int main(){
    int N; cin>>N;
    for(int w=0; w<N; ++w){
        for(int i=0; i<10 ;++i){
            string s; cin>>s;
            for(int j=0; j<10; ++j){
                arr[w][i][j]=s[j]-'0';
            }
        }
    }
    int k; cin>>k;
    cin.ignore();
    while(k--){
        init();
        string s; getline(cin, s);
        // cout << "sizeof :"<<s<<"="<<s.size()<<'\n';
        int a=0;
        for(auto it:s){
            if(it>='0' && it<='9'){
                a=a*10+it-'0';
            }
            else {
                f(a);
                a=0;
            }
        }
        f(a);
        for(int i=0; i<10; ++i){
            for(int j=0; j<10; ++j){
                printf("%02d", temp[i][j]);
                if(j!=9) cout << " ";
            }
            cout << '\n';
        }
        if(k!=0) cout << '\n';
    }
}