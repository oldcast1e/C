#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

void wordlength(int len,char *arr, int *word, int wordnum, int wordcnt){
    for(int i=0;i<len;i++){//배열 길이만큼 반복
        if(arr[i+1] == '\0'){//문자열의 끝인경우
            word[wordnum] = wordcnt;//단어 길이 저장
            wordnum ++;//단어 개수 증가
            wordcnt  = 0;//단어 길이 매개변수 초기화
        }
        else if(arr[i] != ' ') wordcnt ++;//단어의 길이 증가
        else{
            word[wordnum] = wordcnt;//단어 길이 저장
            wordnum ++;//단어 개수 증가
            wordcnt  = 0;//단어 길이 매개변수 초기화
        }
    }
}



void make_rst_arr(int ya,int yb,char *rsta,char *rstb,int rstcnt, char rstarr){
    
}

int main(){

    char inputarr[2][100];//배열 선언
    char rstarr[100][100];//결과 배열
    int rstcnt = 0,wordcnt[2]={0,0};//결과 배열 매개 변수

    for(int i=0;i<2;i++)gets(inputarr[i]);
    
    int inputlen[2];
    for(int i=0;i<2;i++)inputlen[i] = strlen(inputarr[i]);
    //배열 길이

    int word[2][100] = {0};//단어개수
    int wordnum[2] = {0,0};//매개변수
    int word_xy[2][2] = {{0,0},{0,0}};//행렬
    for(int i=0;i<2;i++) wordlength(inputlen[i], inputarr[i],word[i],wordnum[i],wordcnt[i]);
    ////
    char **rsta = NULL;//단어 배열 동적할당 초기화
    rsta = (char **)malloc((wordnum[0])*sizeof(char *));//단어 배열 동적할당
    if( rsta == NULL){
        printf("Error");
        return -1;
    }//에러 확인

    char **rstb = NULL;//단어 배열 동적할당 초기화
    rstb = (char **)malloc((wordnum[1])*sizeof(char *));//단어 배열 동적할당
    if( rstb == NULL){
        printf("Error");
        return -1;
    }//에러 확인

    for(int i=0;i<wordnum[0];i++)rsta[i] = (char *)malloc(word[0][i]*sizeof(char)+1);//문자 배열 동적할당
    for(int i=0;i<wordnum[1];i++)rstb[i] = (char *)malloc(word[1][i]*sizeof(char)+1);//문자 배열 동적할당

    word[0][1] = wordsave(inputlen[0],inputarr[0],word_xy[0][0],word_xy[0][1],rsta);
    //rsta
    word[1][1] = wordsave(inputlen[1],inputarr[1],word_xy[1][0],word_xy[1][1],rstb);
    //rstb
}
/*

*/