#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int num[10],i=0;
    int max = 0;
    while(10>max){
        scanf("%d",&num[i]); 
        if(i%2!=0){//i가 홀수인 경우는 비교/연산자
            if(num[i]== 61 ||num[i]== 10 ) break;
            printf("[홀수] i = %d | num[i] = %d\n",i,num[i]);
        
        }
        else {printf(">>num[%d] = %d\n",i,num[i]);}
        i++;
        max ++;
    }
    //printf("%d",num[i]);
 
} 
//num[i-1] = num[i-1] num[i+1];
/*
123 + 456 * 11 / 11 =
0   1  2  3  4 5  6  7
*/