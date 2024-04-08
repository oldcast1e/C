#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    
    int data[][2] = {{10,20},{30,40},{50,60},{70,80},{90,100}};
    int (*pdata)[2] = data; //배열을 포인터화

    int *ptr[5] // 포인터 배열
    for(int i=0;i<5;i++) ptr[i] = &pdata[i][0];

    for(int i=0;i<5;i++){
        printf("pdata : 0x%p, **ptr : %d, *(*ptr+1) : %d\n",pdata,**ptr,*(*pdata+1));
        ptr++;
    }

}