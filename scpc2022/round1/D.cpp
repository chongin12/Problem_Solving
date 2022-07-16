#include <bits/stdc++.h>
using namespace std;
string X,Y;
int xSize,ySize;
vector<int> getPartialMatch(const string& M) {
    int m = M.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (M[begin + matched] == M[matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
        } else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}
vector<int> kmpSearch(const string & N, const string & M) {
    vector<int> ret;
    vector<int> pi = getPartialMatch(M);
    int n = N.size(), m = M.size();
    int begin = 0, matched = 0;
    while (begin <= n - m) {
        if (matched < m && N[begin + matched] == M[matched]) {
            ++matched;
            if (matched == m) ret.push_back(begin);
        } else {
            if (matched == 0) {
                ++begin;
            } else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}
void init(){
    
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        init();
        cout << "Case #"<<t<<endl;
        cin>>xSize>>ySize;
        cin>>X>>Y;
        int temp=0; // Y에 a만 있으면 1, b만 있으면 2, 둘 다 있으면 3
        for(int i=0; i<ySize; ++i){
            if(Y[i]=='a') temp|=1;
            else if(Y[i]=='b') temp|=2;
        }
        if(temp==1){
            int cnt=0;
            for(int i=0; i<xSize; ++i){
                if(X[i]=='a') cnt++;
            }
            if(cnt>=ySize){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
            continue;
        }
        else if(temp==2){
            int cnt=0;
            for(int i=0; i<xSize; ++i){
                if(X[i]=='b') cnt++;
            }
            if(cnt>=ySize){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
            continue;            
        }
        else{
            int aLeft=0, aRight=ySize-1, bLeft=0, bRight=ySize-1;
            if(Y[0]=='a'){
                int i;
                for(i=0; i<ySize; ++i){
                    if(Y[i]!='a') break;
                    aLeft=i;
                }
                for(;i<ySize; ++i){
                    if(Y[i]!='b') break;
                    bLeft=i;
                }
            }
            else {
                int i;
                for(i=0; i<ySize; ++i){
                    if(Y[i]!='b') break;
                    bLeft=i;
                }
                for(;i<ySize; ++i){
                    if(Y[i]!='a') break;
                    aLeft=i;
                }
            }

            if(Y[ySize-1]=='a'){
                int i;
                for(i=ySize-1; i>=0; --i){
                    if(Y[i]!='a') break;
                    aRight=i;
                }
                for(;i>=0; --i){
                    if(Y[i]!='b') break;
                    bRight=i;
                }
            }
            else {
                int i;
                for(i=ySize-1; i>=0; --i){
                    if(Y[i]!='b') break;
                    bRight=i;
                }
                for(;i>=0; --i){
                    if(Y[i]!='a') break;
                    aRight=i;
                }
            }

            // cout << "aLeft : " << aLeft << ", aRight : " << aRight << '\n';
            // cout << "bLeft : " << bLeft << ", bRight : " << bRight << '\n';
            int fixLeft, fixRight;
            char leftToFind, rightToFind;
            int leftToFindCnt, rightToFindCnt;
            if(aLeft<bLeft){
                fixLeft=aLeft+1;
                leftToFind='a';
                leftToFindCnt=fixLeft;
            }
            else{
                fixLeft=bLeft+1;
                leftToFind='b';
                leftToFindCnt=fixLeft;
            }

            if(bRight>aRight){
                fixRight=bRight-1;
                rightToFind='b';
                rightToFindCnt=ySize-fixRight-1;
            }
            else{
                fixRight=aRight-1;
                rightToFind='a';
                rightToFindCnt=ySize-fixRight-1;
            }
            // cout << "fixLeft : " << fixLeft << ", fixRight : " << fixRight << '\n';
            if(fixLeft>fixRight) { // 쌍이 하나밖에 없는 것.
                int r=0;
                for(int i=0; i<xSize && r<ySize; ++i){
                    if(X[i]==Y[r]) r++;
                }
                if(r==ySize){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
                continue;
            }
            string toFind="";
            for(int i=fixLeft; i<=fixRight; ++i){
                toFind+=Y[i];
            }
            vector<int> sol=kmpSearch(X, toFind);
            bool flag=false;
            for(auto it:sol){
                if(flag) break;
                int cntLeft=0, cntRight=0;
                // it-1부터 앞에 leftToFind가 leftToFindCnt개 있는지 확인.
                for(int i=it-1; i>=0 && cntLeft<leftToFindCnt; --i){
                    if(X[i]==leftToFind) cntLeft++;
                }
                if(cntLeft!=leftToFindCnt) continue;

                // it+(fixRight-fixLeft+1)부터 뒤에 rightToFind가 rightToFindCnt개 있는지 확인
                for(int i=it+fixRight-fixLeft+1; i<xSize && cntRight<rightToFindCnt; ++i){
                    if(X[i]==rightToFind) cntRight++;
                }
                if(cntRight==rightToFindCnt) flag=true;
            }

            if(flag){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }

        }
    }
}