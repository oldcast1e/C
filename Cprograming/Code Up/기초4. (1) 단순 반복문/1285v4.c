#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int num,i=0,pre,max = 0;
    char key = '_',chc;
    
    while(1){
        if(i%2==0){//인덱스가 짝수인 경우 = 숫자
            scanf("%d",&num);
            // printf("[인덱스 짝수입력| 입력된 숫자: %d]\n",num);
            if(key == '_'){
                pre = num;
            }
            else if(key == '+'){num = pre + num; pre =  num; }
            else if(key == '-'){num = pre - num; pre =  num; }
            else if(key == '*'){num = pre * num; pre =  num; }
            else if(key == '/'){num = pre / num; pre =  num; }

        }
        else if(i%2!=0){
            scanf("%c",&chc); if(chc == '=') break;
            // printf("[인덱스 홀수입력| 부호 =  %c]\n",chc);
            key = chc;
        }
        i++;
    }printf("%d",num);
 
} 
/*
인덱스가 짝수인경우 = 숫자
인덱스가 홀수인경우 = 문자
나눠서 입력받을 것.

*/