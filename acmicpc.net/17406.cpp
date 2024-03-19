#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int ori[51][51];
int arr[51][51];
vector<vector<int> > v;
void init(){
    for(int i=0; i<51; ++i){
        for(int j=0; j<51; ++j){
            arr[i][j]=ori[i][j];
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M>>K;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            cin>>ori[i][j];
        }
    }
    for(int i=0; i<K; ++i){
        v.push_back(vector<int>());
        for(int j=0; j<3; ++j){
            int a; cin>>a;
            v.back().push_back(a);
        }
    }
    int res=987654321;
    // init();
    // for(int i=1; i<=N; ++i){
    //     int acc=0;
    //     for(int j=1; j<=M; ++j){
    //         acc+=arr[i][j];
    //     }
    //     res=min(res,acc);
    // }
    sort(v.begin(), v.end());
    do {
        init();
        for(auto it=v.begin(); it!=v.end(); ++it){
            int r=(*it)[0], c=(*it)[1], s=(*it)[2];
            // cout << "r : " << r << ", c : " << c << ", s : " << s << '\n';
            /*
            phase 0 : (r-s, c-s) ~ (r-s, c+s)
            phase 1 : (r-s, c+s) ~ (r+s, c+s)
            phase 2 : (r+s, c+s) ~ (r+s, c-s)
            phase 3 : (r+s, c-s) ~ (r-s, c-s)
            */
            for(int i=1; i<=s; ++i){
                int prev=arr[r-i][c-i];
                for(int j=c-i+1; j<=c+i; ++j){
                    int temp=arr[r-i][j];
                    arr[r-i][j]=prev;
                    prev=temp;
                }
                for(int j=r-i+1; j<=r+i; ++j){
                    int temp=arr[j][c+i];
                    arr[j][c+i]=prev;
                    prev=temp;
                }
                for(int j=c+i-1; j>=c-i; --j){
                    int temp=arr[r+i][j];
                    arr[r+i][j]=prev;
                    prev=temp;
                }
                for(int j=r+i-1; j>=r-i; --j){
                    int temp=arr[j][c-i];
                    arr[j][c-i]=prev;
                    prev=temp;
                }
            }
        }
        for(int i=1; i<=N; ++i){
            int acc=0;
            for(int j=1; j<=M; ++j){
                acc+=arr[i][j];
            }
            res=min(res,acc);
        }
    } while(next_permutation(v.begin(), v.end()));
    cout << res << '\n';
}