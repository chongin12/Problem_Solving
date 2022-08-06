#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int arr[256][256];
pii dp[70][70][70]; // i행 j~k 최댓값, 최솟값
void init(){
    for(int i=0; i<256; ++i){
        for(int j=0; j<256; ++j){
            arr[i][j]=0;
        }
    }
    for(int i=0; i<70; ++i){
        for(int j=0; j<70; ++j){
            for(int k=0; k<70; ++k){
                dp[i][j][k]={0,0};
            }
        }
    }
}
bool f(int x1, int y1, int x2, int y2){
    int Max=arr[x1][y1], Min=arr[x1][y1];
    for(int i=x1; i<=x2; ++i){
        Max=max(Max,dp[i][y1][y2].first);
        Min=min(Min,dp[i][y1][y2].second);
    }
    if(Max-Min+1==(y2-y1+1)*(x2-x1+1)) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        init();
        cout << "Case #"<<t<<endl;
        int N; cin>>N;
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                cin>>arr[i][j];
            }
        }
        for(int i=0; i<N; ++i){
            int Max, Min;
            for(int j=0; j<N; ++j){
                Max=arr[i][j], Min=arr[i][j];
                for(int k=j; k<N; ++k){
                    Max=max(Max,arr[i][k]);
                    Min=min(Min,arr[i][k]);
                    dp[i][j][k]={Max,Min};
                    // cout << "dp["<<i<<"]["<<j<<"]["<<k<<"]="<<dp[i][j][k].first<<","<<dp[i][j][k].second<<'\n';
                }

            }
        }
        int res=0;
        for(int x1=0; x1<N; ++x1){
            for(int y1=0; y1<N; ++y1){
                for(int x2=x1; x2<N; ++x2){
                    for(int y2=y1; y2<N; ++y2){
                        if(f(x1,y1,x2,y2)) res++;
                    }
                }
            }
        }
        cout << res << endl;
    }
}