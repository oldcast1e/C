#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){//메인함수

    int N,cnt=0;
    int spn,len,minlen= 101,minspn= 101;
    //입력받은 문자열의 매개변수 설정
    char *score = NULL;//포인터 선언 및 초기화
    char word[100];//포인터 선언 및 초기화

    scanf("%d",&N);//입력받음
    getchar();
    score = (char*)malloc(100*sizeof(char));//동적할당
    for(int i=0;i<N;i++){//N번 반복
        gets(score);
        len = strlen(score);//문자열을 입력받고 길이 구하ㅣ기

        cnt  = 0;
        for(int j=0;j<len;j++)  if(*(score+j)==' ') cnt ++;
        //공백의 개수 세기
        // printf("len = %d | cnt = %d\n",len,cnt);

        if(len < minlen && cnt <= minspn ){
            minlen = len;
            minspn = cnt;
            strcpy(word,score);
        }//가장 길이가 작은 공백을 포함하는 문자열구하기
    }
    printf("%s",word);
    free(score);//해제
}

/*
Program
Good
This is string
language
*/