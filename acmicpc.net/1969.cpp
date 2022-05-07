#include <bits/stdc++.h>
using namespace std;
int dist(string s1, string s2){
    int cnt=0;
    for(int i=0; i<s1.size(); ++i){
        if(s1[i]!=s2[i]) cnt++;
    }
    return cnt;
}
int main(){
    int N, M; cin>>N>>M;
    vector<string> v;
    for(int i=0; i<N; ++i){
        string s; cin>>s;
        v.push_back(s);
    }
    string res="";
    for(int i=0; i<M; ++i){
        int arr[4]={0,};//a, c, g, t
        for(int j=0; j<N; ++j){
            if(v[j][i]=='A') arr[0]++;
            else if(v[j][i]=='C') arr[1]++;
            else if(v[j][i]=='G') arr[2]++;
            else arr[3]++;
        }
        int k=0;
        for(int j=1; j<4; ++j){
            if(arr[k]<arr[j]) k=j;
        }
        if(k==0) res+='A';
        else if(k==1) res+='C';
        else if(k==2) res+='G';
        else res+='T';
    }
    int cnt=0;
    for(int i=0; i<N; ++i){
        cnt+=dist(res, v[i]);
    }
    cout << res << '\n';
    cout << cnt << '\n';
}