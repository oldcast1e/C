#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    char str[100];//배열 선언
    gets(str);//입력
    int len = strlen(str);//배열 길이
    int wordnum = 0,x=0,y=0,cnt=0;//매개변수 선언
    int word[100] = {0};//단어 개수 저장 배열

    for(int i=0;i<len;i++){//배열 길이만큼 반복
        if(str[i+1] == '\0'){//문자열의 끝인경우
            // printf("--");
            word[wordnum] = cnt;//단어 길이 저장
            wordnum ++;//단어 개수 증가
            cnt  = 0;//단어 길이 매개변수 초기화
        }
        else if(str[i] != ' ')cnt ++;//단어의 길이 증가
        else{
            word[wordnum] = cnt;//단어 개수 저장
            wordnum ++;//단어 개수 증가
            cnt  = 0;//단어 길이 매개변수 초기화
        }
    }
    // printf("%d",wordnum);
    // for(int i=0;i<wordnum;i++)printf("%d ",word[i]);

    char **rst = NULL;//단어 배열 동적할당 초기화
    rst = (char **)malloc((wordnum)*sizeof(char *));//단어 배열 동적할당
    // 포인터 배열의 크기는 단어의 수와 같음
    for(int i=0;i<wordnum;i++)rst[i] = (char *)malloc(word[i]*sizeof(char)+1);//문자 배열 동적할당
    // 각 문자 배열은 단어의 길이+1의 크기
    
    //(2) 저장된 단어들을 길이가 가장 긴 단어부터 짧은 단어까지 정렬하여 출력한다. 
    //길이가 같은 단 어는 사전 순서상 빠른 단어부터 정렬한다.
    for(int i=0;i<len;i++){//단어의 길이만큼 반복
        if(str[i] != ' ' && str[i] != '\n' ){//공백 혹은 종결일때
            rst[y][x] = str[i];//해당 열에 문자저장
            x++;//행 증가
        }
        else{
            x = 0;//행 초기화
            y++;//열 증가
        }
    }
    y++;//단어의 개수 맞추기 위함
    // for(int i=0;i<y;i++)printf("%s\n",rst[i]);

    for(int i=0;i<y;i++){//단어의 개수만큼 반복
        for(int j=0;j<y;j++){//단어의 개수만큼 반복
            if(i!=j){
                if(strlen(rst[i])>strlen(rst[j])){//단어의 길이 비교
                    char tmp[100];

                    strcpy(tmp,rst[i]);
                    strcpy(rst[i],rst[j]);//스왑
                    strcpy(rst[j],tmp);
                }
                else if(strlen(rst[i]) == strlen(rst[j])){//단어의 사전순
                    if(strcmp(rst[i],rst[j])<0){
                        char tmp[100];

                        strcpy(tmp,rst[i]);
                        strcpy(rst[i],rst[j]);//스왑
                        strcpy(rst[j],tmp);
                    }
                }
            }
        }
    }
    for(int i=0;i<y;i++)printf("%s\n",rst[i]);//결과출력

    free(rst);//할당 해제



}
/*

*/