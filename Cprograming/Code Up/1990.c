#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char *num;
    int cnt = 0;
    scanf("%s",num);
    for(int i=0;i<(int)strlen(num);i++){
        cnt += atoi(num[i]);
    }

    printf(">> %d",cnt);
}
/*
자연수 n이 입력되면 3의 배수인지 아닌지 판별하시오.

*/