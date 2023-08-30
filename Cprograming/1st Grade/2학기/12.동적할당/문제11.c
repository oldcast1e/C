#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    int cnt=0,mul = 5;
    int *num = NULL;//동적할당
    num = (int*)malloc(mul);

    while(1){
        
        scanf("%d",&num[cnt]);
        if(num[cnt] == -1) break;
        
        int *tmp = (int*)malloc(mul+3);
        for(int i = 0;i<mul;i++){
            tmp[i] = num[i];
        }
        free(num);
        num = tmp;
        
        mul += 3;
        cnt ++;
    }
    for(int i=0;i<cnt+1;i++) printf(" %d",num[i]);
    // printf("\ncnt = %d",cnt);

}
/*
사용자로부터 -1을 입력받기 전까지 계속 정수를 입력받는다. 

초기 배열 의 크기는 5로 설정하되, 
사용자가 계속 입력하면 길이를 3씩 증가시킨다. 

길이를 증가시킬 때, 새 로운 배열을 하나 만들어서 증가시킨다. 
사용자가 -1을 입력하면 배열의 값을 모두 출력한다.
*/