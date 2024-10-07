#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> v[2];
int main(){
    int M; cin>>M;
    int s=-1, e=-1;
    int totalWhites=0;
    for(int k=0; k<2; ++k){
        string str; cin>>str;
        for(int i=0; i<str.size(); ++i){
            if(str[i]=='.') totalWhites++;
            if(str[i]=='#'){
                if(s!=-1){
                    v[k].push_back({s,e});
                    s=-1, e=-1;
                }
            }
            else {
                if(s==-1){
                    s=i, e=i;
                } else {
                    e=i;
                }
            }
        }
        if(s!=-1) v[k].push_back({s,e});
        s=-1, e=-1;
    }
    
    int nowV = 0, nowIdx=0;
    if(v[0].size()==0) nowV=1;
    else if(v[1].size()==0) nowV=0;
    else if(v[0][0].first!=0) nowV=1;
    else if(v[1][0].first==0 && v[0][0].second < v[1][0].second) nowV=1;
    int res=0;
    while(1){
        // 현재 nowV의 nowIdx의 second보다 작은 (nowV+1)%2의 first들 중 가장 큰 idx를 찾자
        int nowSecond = v[nowV][nowIdx].second;
        if(nowSecond==M-1) break;
        int tempIdx=-1;
        for(int i=v[(nowV+1)%2].size()-1; i>=0; --i){
            if(v[(nowV+1)%2][i].first<=nowSecond){
                tempIdx=i;
                break;
            }
        }
        if(tempIdx==-1) break;
        
        //nowV의 nowIdx의 first부터 해당 first까지 거리를 res에 더하고 nowV와 nowIdx 반영
        res+=v[(nowV+1)%2][tempIdx].first-v[nowV][nowIdx].first+1;
        nowV=(nowV+1)%2;
        nowIdx = tempIdx;
    }
    res+=v[nowV][nowIdx].second - v[nowV][nowIdx].first + 1;
    cout << totalWhites-res << '\n';
}