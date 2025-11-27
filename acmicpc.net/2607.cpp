#include <bits/stdc++.h>
using namespace std;
int arr[26];
vector<string> v;
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        string s; cin>>s;
        v.push_back(s);
    }
    int res=0;
    for(auto it:v[0]){
        arr[it-'A']++;
    }
    for(int i=1; i<N; ++i){
        vector<int> temp(26);
        for(auto it:v[i]){
            temp[it-'A']++;
        }
        int cnt=0;
        int sum=0;
        vector<int> cntIdx;
        for(int j=0; j<26; ++j){
            int k = arr[j]-temp[j];
            if(k>=2) cnt=999;
            sum+=k;
            if(k!=0) {
                cnt++;
                cntIdx.push_back(j);
            }
        }
        if(cnt==2 && sum==0 && v[0].size()==v[i].size()){
            res++;
        }
        else if(cnt==1 && abs(sum)==1) res++;
        else if(cnt==0) res++;
    }
    cout << res << '\n';
}

/*
2
AAABBC
AAABCC

ans : 0

2
AAABBC
AAABBB

ans : 1

2
AAABBDD
AAABBCC

ans : 0
*/