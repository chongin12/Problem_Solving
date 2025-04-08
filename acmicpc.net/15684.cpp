#include <bits/stdc++.h>
using namespace std;
int N, M, H;
int arr[31][11];
bool res=false;
void f(int previ, int prevj, int depth){
    if(depth==0){
        int cur[31];
        for(int i=1; i<=N; ++i) cur[i]=i;
        for(int i=1; i<=H; ++i){
            for(int j=1; j<N; ++j){
                if(arr[i][j]){
                    swap(cur[j], cur[j+1]);
                }
            }
        }

        for(int i=1; i<=N; ++i) {
            if(cur[i]!=i) return;
        }

        res=true;
        
        return;
    }
    for(int i=1; i<=H; ++i){
        if(i<previ) continue;
        for(int j=1; j<N; ++j){
            if(i==previ && j<=prevj) continue;
            if(arr[i][j]==0 && arr[i][j-1]==0 && arr[i][j+1]==0){
                arr[i][j]=1;
                f(i, j, depth-1);
                arr[i][j]=0;
            }
        }
    }
}
int main(){
    cin>>N>>M>>H;
    for(int i=0; i<M; ++i){
        int a, b; cin>>a>>b;
        arr[a][b]=1;
    }

    f(0, 0, 0);
    if(res) {
        cout << "0\n";
        return 0;
    }
    f(0, 0, 1);
    if(res) {
        cout << "1\n";
        return 0;
    }
    f(0, 0, 2);
    if(res) {
        cout << "2\n";
        return 0;
    }
    f(0, 0, 3);
    if(res) {
        cout << "3\n";
        return 0;
    }
    cout << "-1\n";
    
}