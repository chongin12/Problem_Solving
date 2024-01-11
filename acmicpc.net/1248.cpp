#include <bits/stdc++.h>
using namespace std;
int arr[11][11];
int sign[11];
int temp[11][11];
int N;

bool isSameSign(int a, int b){
    if(a>0 && b>0) return true;
    if(a<0 && b<0) return true;
    if(a==0 && b==0) return true;
    return false;
}
void f(int phase){
    if(phase==N){
        for(int i=0; i<N; ++i){
            cout << temp[i][i] << ' ';
        }
        cout << '\n';
        exit(0);
    }
    for(int k=1; k<=10; ++k){
        temp[phase][phase]=k*sign[phase];
        bool flag=true;
        for(int i=phase-1; i>=0; --i){
            temp[i][phase]=temp[i+1][phase]+temp[i][i];
            if(!isSameSign(temp[i][phase], arr[i][phase])){
                flag=false;
                break;
            }
        }
        if(flag) f(phase+1);
    }
}
int main(){
    cin>>N;
    string str; cin>>str;
    int cnt=0;
    for(int i=N; i>0; --i){
        for(int j=0; j<i; ++j){
            if(str[cnt]=='+') arr[N-i][N-i+j]=1;
            else if(str[cnt]=='-') arr[N-i][N-i+j]=-1;
            else arr[N-i][N-i+j]=0;
            cnt++;
        }
    }
    for(int i=0; i<N; ++i){
        sign[i]=arr[i][i];
    }
    f(0);
}