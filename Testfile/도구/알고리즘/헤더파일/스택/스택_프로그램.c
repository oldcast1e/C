#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "IntStack.h"
int main(void){
    int ipt,tmp,check;
    IntStack stt;
    if(Initialisze(&stt,64) == -1)return -1;

    while(1){

        printf("현재 데이터 수: %d/%d\n",Size(&stt),Capacity(&stt));
        printf("(1)푸시 (2)팝 (3)피크 (4)출력 (0)종료 : ");scanf("%d",&ipt);

        if(ipt == 0) break;
        switch(ipt){
            case 1:
                printf("푸시 할 데이터: ");scanf("%d",&tmp);
                check = Push(&stt,tmp);
            break;
            case 2:
                // printf(" 할 데이터: ");scanf("%d",&tmp);
                check = Pop(&stt,&tmp);//tmp에 팝한 데이터 저장
                printf(">>팝한 데이터 : %d\n",tmp);
            break;
            case 3:
                // printf(" 할 데이터: ");scanf("%d",&tmp);
                check = Peek(&stt,&tmp);//tmp에 팝한 데이터 저장
                printf(">>피크한 데이터 : %d\n",tmp);
            break;
            case 4:
                Print(&stt);
            break;

            // default Terminate(&stt);
        }
    }
    
}