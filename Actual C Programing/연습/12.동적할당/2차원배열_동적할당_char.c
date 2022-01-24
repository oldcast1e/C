#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    int N,M;//N개의 정수형 값 저장
    printf("입력할 문자열의 개수를 입력하세요: ");
    scanf("%d",&N);
    getchar();

    char **string = NULL;
    string = (char **)malloc(N*sizeof(char *));
    //malloc의 sizeof에 포인터를 인자로 할 것!
    //N*1(char)이므로 N개를 저장할 배열을 만들 수 있음
    for(int i=0;i<N;i++) string[i] = (char *)malloc(100*sizeof(char));
    //2차원 배열을 위해 한번 더 동적할당 진행 - 크기 100

    if( string == NULL){
        printf("Error");
        return -1;
    }//에러 확인

    for(int i=0;i<N;i++) gets(string[i]);
    for(int i=0;i<N;i++) printf("Input: %s\n",string[i]);

    for(int i=0;i<N;i++) free(string[i]);//1차원 배열 해제
    free(string);//포인터 연결 해제
}

