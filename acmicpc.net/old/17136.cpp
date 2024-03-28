#include <iostream>
#define INF 123456789
#define iMAX 10
#define jMAX 10
using namespace std;
int arr[10][10];
int garo_seq[10][10];
int sero_seq[10][10];
int paper[6]={0, 5, 5, 5, 5, 5};
int result=INF;


void f(int i, int j, int one_count, int paper_count){
    if(j == jMAX) {
        f(i+1, 0, one_count, paper_count);
        return;
    }
    if(i == iMAX){
        return;
    }
    if(arr[i][j]==0){
        f(i, j+1, one_count, paper_count);
        return;
    }
    else {
        for(int size=5; size>=1; --size){
            if(paper[size]<=0 || i+size>iMAX || j+size>jMAX){
                continue;
            }
            int good=1;
            for(int t1=i; t1<i+size; ++t1){
                for(int t2=j; t2<j+size; ++t2){
                    if(arr[t1][t2]==0) {
                        good=0;
                        break;
                    }
                }
                if(!good) break;
            }
            if(good) {
                if(one_count == size*size){
                    if(result>paper_count+1) result = paper_count+1;
                    return;
                }
                paper[size]--;
                for(int t1=i; t1<i+size; ++t1){
                    for(int t2=j; t2<j+size; ++t2){
                        arr[t1][t2]=0;
                    }
                }
                f(i, j+size, one_count-size*size, paper_count+1);
                for(int t1=i; t1<i+size; ++t1){
                    for(int t2=j; t2<j+size; ++t2){
                        arr[t1][t2]=1;
                    }
                }
                paper[size]++;
            } 
        }
    }
}
int main(){
    int cnt=0;
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==1){
                cnt++;
            }
        }
    }
    f(0, 0, cnt, 0);
    if(cnt==0) printf("0");
    else if(result==INF) printf("-1");
    else printf("%d", result);
}
/*
0 1 1 1 1 0 0 0 0 0 
0 1 1 1 1 0 0 0 0 0 
1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
*/