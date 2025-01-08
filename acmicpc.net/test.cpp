#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

pii operator+(pii a, pii b){
    return {a.first+b.first, a.second+b.second};
}
pii operator-(pii a, pii b){
    return {a.first-b.first, a.second-b.second};
}

pii countTowAndFive(int X) {
    int two=0, five=0;
    while(X%2==0){
        two++;
        X/=2;
    }
    while(X%5==0){
        five++;
        X/=5;
    }
    return {two, five};
}

pii customMax(pii a, pii b){
    auto aMin = min(a.first, a.second);
    auto bMin = min(b.first, b.second);
    if(aMin>=bMin) return a;
    return b;
}

int solution(vector<vector<int>> A){
    int N=A.size(), M=A[0].size();
    pii rowAcc[401][401];
    pii colAcc[401][401];
    pii nowInfo[401][401]; // A와 시작좌표가 다른거 주의! (1,1부터)
    memset(rowAcc, 0, sizeof rowAcc);
    memset(colAcc, 0, sizeof colAcc);
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            // 1. 각 숫자마다 2와 5가 몇개 있는지 카운트
            pii a = countTowAndFive(A[i][j]);
            // cout << A[i][j] << " two, five : " << a.first << " , " << a.second << '\n';
            nowInfo[i+1][j+1]=a;
            int two = a.first, five = a.second;

            // 2. 누적합에 카운트해주기
            // 2-1. row에 카운트 (이제 (1,1)부터 시작하는 인덱스로 바꿈)
            rowAcc[i+1][j+1]=rowAcc[i][j+1]+a;

            // 2-2. column에 카운트
            colAcc[i+1][j+1]=colAcc[i+1][j]+a;
        }
    }

    pii res(0,0);

    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            // cout << "rowAcc["<<i<<"]["<<j<<"]="<<rowAcc[i][j].first << ","<<rowAcc[i][j].second<<'\n';
            // cout << "colAcc["<<i<<"]["<<j<<"]="<<colAcc[i][j].first << ","<<colAcc[i][j].second<<'\n';
            // 현재 좌표에서 꺾어지는 모든 경우 구하기.
            // 1. 위쪽 왼쪽
            res=customMax(res,rowAcc[i][j]+colAcc[i][j]-nowInfo[i][j]);

            // 2. 위쪽 오른쪽
            res=customMax(res,rowAcc[i][j]+colAcc[i][M]-colAcc[i][j]);

            // 3. 아래쪽 왼쪽
            res=customMax(res,rowAcc[N][j]-rowAcc[i][j]+colAcc[i][j]);

            // 4. 아래쪽 오른쪽
            res=customMax(res,rowAcc[N][j]-rowAcc[i][j]+colAcc[i][M]-colAcc[i][j]+nowInfo[i][j]);
        }
    }
    return min(res.first, res.second);
}
int main(){
    int N, M; cin>>N>>M;
    vector<vector<int>> A;
    for(int i=0; i<N; ++i){
        vector<int> temp;
        for(int j=0; j<M; ++j){
            int a; cin>>a; temp.push_back(a);
        }
        A.push_back(temp);
    }
    cout << solution(A) << '\n';
}

/*

3 3
10 100 10
1 10 1
1 10 1 

3 4
6 25 4 10
12 25 1 15
7 15 15 5

4 4
5 8 3 1
4 15 12 1
6 7 10 1
9 1 2 1

4 4
7500 10 11 12
6250 13 14 15
134 17 16 1
5500 2093 5120 238

*/