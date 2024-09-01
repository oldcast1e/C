#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void print(int *num, int n , int *cnt){
    num[*cnt] = n%10; //printf(">>%d ",num[*cnt]);
    n/=10; *cnt += 1;
    if(n >0 ) print(num, n ,cnt);
}

int main(){
    int n, *num,cnt;scanf("%d",&n);
    cnt = 0;
    num = (int *)malloc(sizeof(int)*n);
    print(num, n , &cnt);
    // for(int i =cnt -1;i>=0;i--)printf("%d\n",num[i]);
    for(int i =0;i<cnt;i++)printf("%d\n",num[i]);

    
} 
/*

*/