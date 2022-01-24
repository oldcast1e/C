#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){//메인함수

    int N,rst;//입력받을 정수과 출력할 결과값 선언
    char *pstr = NULL;//포인터 선언 및 초기화
    char a,b;//입력받을 문자 2개
    scanf("%d",&N);//정수를 입력받고
    getchar();//엔터값 삭제

    pstr = (char*)malloc(N*sizeof(N));//동적할당

    for(int i=0;i<N;i++){//N번 반복
        scanf("%c",(pstr+i));//문자를 입력받고
    }
    getchar();//엔터 삭제
    scanf("%c %c",&a,&b);//두개의 문자를 입력받고
    rst = 0;//결과값 초기화 1
    for(int i=0;i<N;i++){//문자a를 찾으면 결과값 증가
        if(*(pstr+i)==a) rst++;
    }
    printf("%d ",rst);rst = 0;//결과값 출력 1,//결과값 초기화 2
    for(int i=0;i<N;i++){
        if(*(pstr+i)==b) rst++;//문자b를 찾으면 결과값 증가
    }
    printf("%d ",rst);//결과값 출력 2
    free(pstr);//해제




}