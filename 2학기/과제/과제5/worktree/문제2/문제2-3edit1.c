#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    char A[101]={},B[101]={};//배열 선언
    char rstarr[100][100]={};//결과 배열
    gets(A);
    gets(B);//입력
    int lena = strlen(A),lenb = strlen(B);//배열 길이
    int rstcnt = 0;//결과 배열 매개 변수

    int wordnuma = 0,xa=0,ya=0,cnta=0;//매개변수 선언
    int wordnumb = 0,xb=0,yb=0,cntb=0;//매개변수 선언

    int word_A[101] = {0};//단어 개수 저장 배열
    int word_B[101] = {0};//단어 개수 저장 배열
    
    for(int i=0;i<lena;i++){//배열 길이만큼 반복
        if(A[i+1] == '\0'){//문자열의 끝인경우
            // printf("--");
            word_A[wordnuma] = cnta;//단어 길이 저장
            wordnuma ++;//단어 개수 증가
            cnta  = 0;//단어 길이 매개변수 초기화
        }
        else if(A[i] != ' ')cnta ++;//단어의 길이 증가
        else{
            word_A[wordnuma] = cnta;//단어 개수 저장
            wordnuma ++;//단어 개수 증가
            cnta  = 0;//단어 길이 매개변수 초기화
        }
    }
    for(int i=0;i<lenb;i++){//배열 길이만큼 반복
        if(B[i+1] == '\0'){//문자열의 끝인경우
            // printf("--");
            word_B[wordnumb] = cntb;//단어 길이 저장
            wordnumb ++;//단어 개수 증가
            cntb  = 0;//단어 길이 매개변수 초기화
        }
        else if(B[i] != ' ')cntb ++;//단어의 길이 증가
        else{
            word_B[wordnumb] = cntb;//단어 개수 저장
            wordnumb ++;//단어 개수 증가
            cntb  = 0;//단어 길이 매개변수 초기화
        }
    }

    char **rsta = NULL;//단어 배열 동적할당 초기화
    rsta = (char **)malloc((wordnuma)*sizeof(char *));//단어 배열 동적할당
    if( rsta == NULL){
        printf("Error");
        return -1;
    }//에러 확인
    char **rstb = NULL;//단어 배열 동적할당 초기화
    rstb = (char **)malloc((wordnumb)*sizeof(char *));//단어 배열 동적할당
    if( rstb == NULL){
        printf("Error");
        return -1;
    }//에러 확인

    for(int i=0;i<wordnuma;i++)rsta[i] = (char *)malloc(word_A[i]*sizeof(char)+1);//문자 배열 동적할당
    for(int i=0;i<wordnumb;i++)rstb[i] = (char *)malloc(word_B[i]*sizeof(char)+1);//문자 배열 동적할당

    for(int i=0;i<lena;i++){//단어의 길이만큼 반복
        if(A[i] != ' ' && A[i] != '\n' ){//공백 혹은 종결일때
            rsta[ya][xa] = A[i];//해당 열에 문자저장
            xa++;//행 증가
        }
        else{
            rsta[ya][xa] = '\0';
            xa = 0;//행 초기화
            ya++;//열 증가
        }
    }ya++;//단어의 개수 맞추기 위함
    ///->>>>첫번째 문자열의 단어를 분리하여 배열 rsta 저장

    for(int i=0;i<lenb;i++){//단어의 길이만큼 반복
        if(B[i] != ' ' && B[i] != '\n' ){//공백 혹은 종결일때
            rstb[yb][xb] = B[i];//해당 열에 문자저장
            xb++;//행 증가
        }
        else{
            rstb[yb][xb] = '\0';
            xb = 0;//행 초기화
            yb++;//열 증가
        }
    }yb++;//단어의 개수 맞추기 위함
    ///->>>>두번째 문자열의 단어를 분리하여 배열 rstb 저장

    for(int i=0;i<ya;i++){//첫번째 배열의 길이 만큼 반복
        for(int j=0;j<ya;j++){
            if(i != j){
                char tmp[101];//임의 문자배열 선언
                strcpy(tmp,rsta[i]);strcat(tmp,rsta[j]);
                //문자배열에 A의 해당 번째 단어와 B의 해당번째 단어를 접합
                strcat(tmp,"\0");//문자 배열의 종결을 정의해줌

                for(int k=0;k<yb;k++){//두번째 문자배열의 단어를 모은 배열의 요소개수 만큼 반복
                    if(strcmp(rstb[k],tmp)==0){ //A의 단어(1)와 A의 단어(2)를 접합한 단어가 B의 단어에 존재하면
                        // printf("%s ",rstb[k]);
                        strcpy(rstarr[rstcnt],rstb[k]);//결과배열에 저장하고
                        rstcnt ++;//결과배열 인덱스값 증가
                        strcpy(rstb[k],"-1");//B배열의 비교대상 요소를 -1로 변환
                        strcat(rstb[k],"\0");
                        break;
                    }
                }
            }
        }
    }
    // for(int i=rstcnt-1;i>=0;i--)printf("%s\n",rstarr[i]);//결과출력
    for(int i=0;i<rstcnt;i++){//rstcnt반복
        for(int j=0;j<rstcnt-1;j++){//rstcnt반복
            if(strlen(rstarr[j]) < strlen(rstarr[j+1])){//문자열길이 비교
                char tmp1[101]={};
                strcpy(tmp1,rstarr[j]);strcat(tmp1,"\0");
                strcpy(rstarr[j],rstarr[j+1]);//스왑
                strcpy(rstarr[j+1],tmp1);
            }
            else if(strlen(rstarr[j]) == strlen(rstarr[j+1])){//문자열 길이가 같을때
                if(strcmp(rstarr[j],rstarr[j+1]) > 0){//사전순 비교
                    char tmp2[101]={ };

                    strcpy(tmp2,rstarr[j]);strcat(tmp2,"\0");
                    strcpy(rstarr[j],rstarr[j+1]);//스왑
                    strcpy(rstarr[j+1],tmp2);
                }
            }
        }
    }
    for(int i=0;i<rstcnt;i++)printf("%s\n",rstarr[i]);//결과출력
    
    for(int i=0;i<wordnuma;i++)free(rsta[i]);
    for(int i=0;i<wordnumb;i++)free(rstb[i]);
    free(rsta);//할당 해제
    free(rstb);
}
/*
문자열 A에 포함된 두 개의 단어를 합성하여 만들어진 단어가 문자열 B에 포함되어있으면, 
문자열 B에 포함된 단어(합성하여 만들어지는 단어)를 출력한다. 

출력 순서는 길이가 가장 긴 단어 부터 짧은 단어까지 정렬하여 출력하며, 
길이가 같은 단어는 사전 순서상 빠른 단어부터 출력한다.
red orange yellow green blue purple
pink red redorange orangered yellow black bluegreen white purple

apple or ange pineapple coconuts lemons ora nge
appleapple orange orlemons
*/




