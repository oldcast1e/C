#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "IntQueue.h"
int main(void){
    int ipt,tmp,check;
    IntQueue que;
    if(Initialize(&que,64) == -1)return -1;

    while(1){

        printf("현재 데이터 수: %d/%d\n",Size(&que),Capacity(&que));
        printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (0)종료 : ");scanf("%d",&ipt);

        if(ipt == 0) break;
        switch(ipt){
            case 1:
                printf("인큐 할 데이터: ");scanf("%d",&tmp);
                check = EnQue(&que,tmp);
        
        1    break;
            case 2:
                // printf(" 할 데이터: ");scanf("%d",&tmp);
                check = DeQue(&que,&tmp);//tmp에 팝한 데이터 저장
                printf(">>디큐한 데이터 : %d\n",tmp);
            break;
            case 3:
                // printf(" 할 데이터: ");scanf("%d",&tmp);
                check = Peek(&que,&tmp);//tmp에 팝한 데이터 저장
                printf(">>피크한 데이터 : %d\n",tmp);
            break;
            case 4:
                Print(&que);
            break;

            // default Terminate(&que);
        }
    }
    
}