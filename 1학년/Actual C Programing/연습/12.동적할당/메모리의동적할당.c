#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    int *num = NULL;// 포인터 변수 선언 및 초기화
    num = (int *)malloc(sizeof(int));//동적할당
    //malloc( 메모리 크기 )
    if( num == NULL){
        printf("Error");
        return -1;
    }//에러 확인
    scanf("%d",&*num);
    printf("Input : %d",*num);
    free(num);// 메모리 해제

}