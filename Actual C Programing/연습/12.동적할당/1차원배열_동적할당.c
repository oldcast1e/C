#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    int N;//N개의 정수형 값 저장
    scanf("%d",&N);

    int *num = NULL;
    num = (int *)malloc(N*sizeof(N));
    //N*4(int)이므로 N개를 저장할 배열을 만들 수 있음
    if( num == NULL){
        printf("Error");
        return -1;
    }//에러 확인

    for(int i=0;i<N;i++) scanf("%d",&num[i]);
    for(int i=0;i<N;i++) printf("Input(%d): %d\n",i+1,num[i]);

}