#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//함수를 매개변수로 사용하는 포인터

void PrintPrt(int (*pdata)[2]){
     printf("함수 호출 후\n");
     for(int i=0;i<5;i++){ printf("pdata : %p, *pata : %d\n",pdata,**pdata); pdata ++;}
     printf("\n");
}

int main(){
    int data[][2] = {{10,20},{30,40},{50,60},{70,80},{90,100}};
    int (*pdata)[2] = data;

    printf("함수 호출 전\n");
    for(int i=0;i<5;i++){
      for(int j=0;j<2;j++) printf("pdata : %p, [%d][%d] : %d\n",pdata,i,j,(*pdata)[j]);
      pdata ++;
      printf("\n");
    }

    pdata = data;
    PrintPrt(pdata);
}