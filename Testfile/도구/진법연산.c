#include  <stdio.h>
int main(){
    int N,M;
    char set;
    printf("<계산 할 진수계를 선택하세요>\n8진수: o\n10진수: d\n10진수: x\n");
    printf("계산 할 진수계:");
    scanf("%c",&set);
    if(set == 'd'){
        scanf("%d %d",&N,&M);
        printf("10진수의 더하기 연산값은 %d입니다.\n",N+M);
        printf("10진수의 빼기 연산값은 %d입니다.\n",N-M);
        printf("10진수의 곱하기 연산값은 %d입니다.\n",N*M);
        printf("10진수의 나누기 연산값은 %d입니다.",N/M);
    }
    else if(set == 'o'){
        scanf("%o %o",&N,&M);
        printf("8진수의 더하기 연산값은 %o입니다.\n",N+M);
        printf("8진수의 빼기 연산값은 %o입니다.\n",N-M);
        printf("8진수의 곱하기 연산값은 %o입니다.\n",N*M);
        printf("8진수의 나누기 연산값은 %o입니다.",N/M);
    }
    if(set == 'x'){
        scanf("%x %x",&N,&M);
        printf("16진수의 더하기 연산값은 %x입니다.\n",N+M);
        printf("16진수의 빼기 연산값은 %x입니다.\n",N-M);
        printf("16진수의 곱하기 연산값은 %x입니다.\n",N*M);
        printf("16진수의 나누기 연산값은 %x입니다.",N/M);
    }
   
    
    


}