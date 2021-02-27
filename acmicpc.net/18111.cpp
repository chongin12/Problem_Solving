#include <iostream>
using namespace std;
int arr[300];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, B; cin >> N >> M >> B;
    int minFloor=9999, maxFloor=-1;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            int a; cin >> a;
            if(a>maxFloor) maxFloor=a;
            if(a<minFloor) minFloor=a;
            arr[a]++;
        }
    }
    int time=0;
    while(maxFloor!=minFloor){
        if(arr[minFloor]<=B && arr[minFloor] <= arr[maxFloor]*2){
            B-=arr[minFloor];
            arr[minFloor+1]+=arr[minFloor];
            time+=arr[minFloor++];
        } else {
            B+=arr[maxFloor];
            arr[maxFloor-1]+=arr[maxFloor];
            time+=2*arr[maxFloor--];
        }
    }
    cout << time << " " << maxFloor << '\n';
}