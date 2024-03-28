#include <stdio.h>
int arr[11][11];
int cnt[11];

int find(int a, int b){
    int res=arr[a][0];
    if(b==0) b+=cnt[a];
    for(int i=1; i<b; ++i){
        res=arr[a][res];
    }
    if(res==0) return 10;
    return res;
}

int main(){
    for(int i=0; i<10; ++i){
        arr[i][i] = 1;
        arr[i][0] = i;
        int j=i;
        int c=0;
        while(1){
            ++c;
            int prev=j;
            j=(j*i)%10;
            if(arr[i][j] || i==0) {
                arr[i][prev]=i;
                cnt[i]=c;
                break;
            }
            arr[i][prev]=j;
            
        }
    }
    int a;
    scanf("%d", &a);
    for(int i=0; i<a; ++i){
        int s, w;
        scanf("%d %d", &s, &w);
        printf("%d\n", find(s%10, w%cnt[s%10]));
    }
}