#include <bits/stdc++.h>
using namespace std;
int arr[]={3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1};
int main(){
    int N, M; cin>>N>>M;
    string s1, s2; cin>>s1>>s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int flag=1;
    vector<int> res;
    while(!s1.empty() && !s2.empty()){
        if(flag){
            res.push_back(arr[s1.back()-'A']);
            s1.pop_back();
        }
        else{
            res.push_back(arr[s2.back()-'A']);
            s2.pop_back();
        }
        flag=!flag;
    }
    while(!s1.empty()){
        res.push_back(arr[s1.back()-'A']);
        s1.pop_back();
    }
    while(!s2.empty()){
        res.push_back(arr[s2.back()-'A']);
        s2.pop_back();
    }
    while(1){
        if(res.size()==2){
            break;
        }
        vector<int> v;
        for(int i=1; i<res.size(); ++i){
            v.push_back((res[i]+res[i-1])%10);
        }
        res=v;
    }
    if(res[0]!=0) cout << res[0];
    cout << res[1] << "%\n";
}