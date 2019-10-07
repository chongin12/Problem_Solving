#include <stdio.h>
int main(){
    int a,b,r=0,c=1,i,j;
    scanf("%d %d", &a,&b);
    for(i=1; c<=b; ++i)
        for(j=0; j<i&&c<=b; ++j, ++c)
            if(c<a) continue;
            else r+=i;
    printf("%d", r);
}