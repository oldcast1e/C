#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    scanf("%d %d",&a,&b);
    for(int i=0;i<b;i++){//b번 반복
        for(int j=cnt;j<a-1;j++){
            for(int k=0;k<j;k++)printf(" ");
            printf("*\n");
        }
        
        //for(int k=0;k<a-1;k++)printf(" ");printf("*\n");
        
        for(int j=a-1;j>0;j--){
            for(int k=0;k<j;k++)printf(" ");
            printf("*\n");
        }printf("*\n");
    }
 
} 
/*
높이 h와 반복휫수 r이 주어질때, 별을 다음과 같이 지그재그로 출력하자.

예) 3 2

*
 *
  *
 *
*
*
 *
  *
 *
*
*/