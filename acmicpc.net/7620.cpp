#include <bits/stdc++.h>
using namespace std;
const int MN=17010;
const int INF=987654321;
const unsigned char COPY = 0;
const unsigned char MODIFY = 1;
const unsigned char DELETE = 2;
const unsigned char ADD = 3;

int dp[2][MN];
struct command{
    unsigned char a : 2; // 0 : c, 1 : m, 2 : d, 3 : a
    unsigned char b : 2;
    unsigned char c : 2;
    unsigned char d : 2;
    /*
    a  b

    c  d
    */
};
command dplog[MN/2][MN/2];
void init(int i){
    for(int j=0; j<MN; ++j){
        dp[i%2][j]=INF;
    }
    dp[i%2][0]=i;
}
void addLog(int i, int j, unsigned char val){
    if(i%2==0 && j%2==0) {
        dplog[i/2][j/2].a=val;
    }
    if(i%2==1 && j%2==0) {
        dplog[i/2][j/2].c=val;
    }
    if(i%2==0 && j%2==1) {
        dplog[i/2][j/2].b=val;
    }
    if(i%2==1 && j%2==1) {
        dplog[i/2][j/2].d=val;
    }
}
unsigned char seeLog(int i, int j){
    if(i%2==0 && j%2==0) {
        return dplog[i/2][j/2].a;
    }
    if(i%2==1 && j%2==0) {
        return dplog[i/2][j/2].c;
    }
    if(i%2==0 && j%2==1) {
        return dplog[i/2][j/2].b;
    }
    if(i%2==1 && j%2==1) {
        return dplog[i/2][j/2].d;
    }
    return dplog[i/2][j/2].a;
}
int main(){
    init(0);
    init(1);
    string s1, s2; cin>>s1>>s2;
    for(int j=1; j<=s2.size(); ++j){ // 입력을 쓰지 않고 채우는 경우(추가만)
        dp[0][j]=j;
        addLog(0, j, ADD);
        //cout << "dp["<<0<<"]["<<j<<"]="<<dp[0][j]<<'\n';
    }
    for(int i=0; i<s1.size(); ++i){
        init(i+1);
        for(int j=0; j<s2.size(); ++j){
            //dp[i+1][j+1]을 채울 예정.
            /*
                [i][j]에서 복사 -> +0
                [i][j]에서 수정 -> +1
                [i][j+1]에서 삭제 -> +1
                [i+1][j]에서 추가 -> +1
            */
            if(dp[(i+1)%2][j+1] > dp[i%2][j]+1){// 수정
                dp[(i+1)%2][j+1]=dp[i%2][j]+1;
                addLog(i+1, j+1, MODIFY);
            }
            if(dp[(i+1)%2][j+1] > dp[i%2][j+1]+1){// 삭제
                dp[(i+1)%2][j+1]=dp[i%2][j+1]+1;
                addLog(i+1, j+1, DELETE);
            }
            if(dp[(i+1)%2][j+1] > dp[(i+1)%2][j]+1){// 추가
                dp[(i+1)%2][j+1]=dp[(i+1)%2][j]+1;
                addLog(i+1, j+1, ADD);
            }
            if(s1[i]==s2[j]){
                if(dp[(i+1)%2][j+1] > dp[i%2][j]){// 복사
                    dp[(i+1)%2][j+1]=dp[i%2][j];
                    addLog(i+1, j+1, COPY);
                }
            }
            //cout << (int)seeLog(i+1, j+1) << ' ';
            //cout << "dp["<<i+1<<"]["<<j+1<<"]="<<dp[(i+1)%2][j+1]<<'\n';
        }
        //cout << '\n';
    }
    int nowx=s1.size(), nowy=s2.size();
    string res="";
    while(nowx!=0 || nowy!=0){
        if(nowx==0){
            res+=s2[nowy-1];
            res+='a';
            nowy--;
            continue;
        }
        else if(nowy==0){
            res+=s1[nowx-1];
            res+='d';
            nowx--;
            continue;
        }
        unsigned char val=seeLog(nowx,nowy);
        //cout << "nowx : " << nowx << ", nowy : " << nowy << '\n';
        if(val==COPY){
            //cout << "copy\n";
            res+=s2[nowy-1];
            res+='c';
            nowx--;
            nowy--;
        }
        else if(val==MODIFY){
            //cout << "modify\n";
            res+=s2[nowy-1];
            res+='m';
            nowx--;
            nowy--;
        }
        else if(val==DELETE){
            //cout << "delete\n";
            res+=s1[nowx-1];
            res+='d';
            nowx--;
        }
        else if(val==ADD){
            //cout << "add\n";
            res+=s2[nowy-1];
            res+='a';
            nowy--;
        }
    }
    //cout << res << '\n';
    for(int i=res.size()-1; i>=0; i-=2){
        cout << res[i] << ' ' << res[i-1] << '\n';
    }
}