#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#define swap(tmp,n,m)do{tmp = n;n=m;m=tmp;}while(0)
/**
10개의 정수를 입력으로 받아, 가장 큰 수부터 내림차순으로 정렬하여 출력하는 프로 그램을 작성 하시오.
 */
int main(){
    int num[11],tmp;
    for(int i=0;i<10;i++)scanf("%d",&num[i]);
    for(int i=0;i<10;i++) for(int j=0;j<9;j++)if(num[j] < num[j+1]) swap(tmp,num[j],num[j+1]);
    for(int i=0;i<10;i++)printf("%d ",num[i]);


}