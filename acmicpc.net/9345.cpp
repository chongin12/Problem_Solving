#include <bits/stdc++.h>
using namespace std;
int segMax[100001*4];
int segMin[100001*4];
int MaxQuery(int A, int B, int n, int x, int y){
    if(A<=x && y<=B){
        return segMax[n];
    }
    if(y<A || B<x){
        return -1;
    }
    int mid = (x+y)/2;
    return max(MaxQuery(A, B, n*2, x, mid), MaxQuery(A, B, n*2+1, mid+1, y));
}
int MinQuery(int A, int B, int n, int x, int y){
    if(A<=x && y<=B){
        return segMin[n];
    }
    if(y<A || B<x){
        return 987654321;
    }
    int mid = (x+y)/2;
    return min(MinQuery(A, B, n*2, x, mid), MinQuery(A, B, n*2+1, mid+1, y));
}
int MaxUpdate(int idx, int val, int n, int x, int y){
    if(idx<x || y<idx){
        return segMax[n];
    }
    if(x==y){
        return segMax[n]=val;
    }
    int mid = (x+y)/2;
    segMax[n]=max(MaxUpdate(idx, val, n*2, x, mid), MaxUpdate(idx, val, n*2+1, mid+1, y));
    return segMax[n];
}
int MinUpdate(int idx, int val, int n, int x, int y){
    if(idx<x || y<idx){
        return segMin[n];
    }
    if(x==y){
        return segMin[n]=val;
    }
    int mid = (x+y)/2;
    segMin[n]=min(MinUpdate(idx, val, n*2, x, mid), MinUpdate(idx, val, n*2+1, mid+1, y));
    return segMin[n];
}
void init(){
    memset(segMax, 0, sizeof segMax);
    for(int i=0; i<100001*4; ++i){
        segMin[i]=987654321;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        init();
        int N, K; cin>>N>>K;
        for(int i=0; i<N; ++i){
            MinUpdate(i, i, 1, 0, N-1);
            MaxUpdate(i, i, 1, 0, N-1);
        }
        for(int i=0; i<K; ++i){
            int Q, A, B; cin>>Q>>A>>B;

            if(Q==0){
                int aValue = MaxQuery(A, A, 1, 0, N-1);
                int bValue = MaxQuery(B, B, 1, 0, N-1);
                MaxUpdate(A, bValue, 1, 0, N-1);
                MaxUpdate(B, aValue, 1, 0, N-1);
                MinUpdate(A, bValue, 1, 0, N-1);
                MinUpdate(B, aValue, 1, 0, N-1);
            }
            else{
                int minValue = MinQuery(A, B, 1, 0, N-1);
                int maxValue = MaxQuery(A, B, 1, 0, N-1);
                if(minValue==A && maxValue==B){
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }

}