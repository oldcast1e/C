#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    int N;//정수형 변수 선언 및 입력
    scanf("%d",&N);
    getchar();
    char **str = NULL;//동적할당 포인터 초기화
    str = (char**)malloc(N*sizeof(char*));
    for(int i=0;i<N;i++) str[i] = (char*)malloc(N*sizeof(char));//동적할당 : 2차원배열

    for(int i=0;i<N;i++)gets(str[i]);//입력

    for(int i=0;i<N;i++){//N번 반복
        for(int j=0;j<N;j++){//N번 반복
            if(i!=j){
                if(strcmp(str[i],str[j])<0){//문자열 비교
                    char *tmp;
                    tmp = str[i];
                    str[i] = str[j];
                    str[j] = tmp;//사전순으로 재배열
                }
            } 
        }
    }
    for(int i=0;i<N;i++)puts(str[i]);//결과출력

    
}
/*
정수 N을 입력받고 N개의 문자열을 입력받아 사전 순으로 출력하는 프 로그램을 작성하시오.

apricot 
peach 
willow 
birch
*/