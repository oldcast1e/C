#include<stdio.h>
int main(void){
  
    int n,num[8],cnt=0;
    int rst = 0;
    scanf("%d",&n);

    while(n>0){
        num[cnt] = n%16;
        // printf("<%d>\n",n%16);
        n /= 16;
        cnt++;
    }
    for(int i=cnt-1;i>=0;i--){
        rst += num[i];
        if(i!=0)rst *= 10;
    }
    printf("rst = %d",rst);
}