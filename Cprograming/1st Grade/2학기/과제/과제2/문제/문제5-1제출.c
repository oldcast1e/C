#include  <stdio.h>
#include <string.h>
int main(){//메인함수
    char arr[1001]={},*parr = arr,word[102][100];//문장배열과 단어 배열 선언
    strcpy(word[100]," \n");//문자열 분리 요소
    strcpy(word[101]," ");//초기화
    // word[100] = " \n";
    // word[101] = "  ";
    

    int N,len= 0,cnt=0,wordcnt=0;//입력받을 정수와 배열과 관련된 매개변수 정의 및 초기화
    int val = 0;//Nㄱ번째 단어를 찾기위한 매개변수
    int max = -1,samemax=1000,rstnum;//길이 최대값 초기화 및 인덱스 넘버 매개변수
    gets(arr);//배열을 입력받음
    scanf("%d",&N);//정수를 입력받음
    // for(int i=0;;i++){
    //     scanf("%c",(parr+i));
    //     if(*(parr+i)=='\n') break;
    // }
    char *token;//분리요소 정의
    token = strtok(arr,word[100]);//토큰 초기화
    while(token != NULL){//배열의 끝가지
        // printf("token = %s\n",token);
        strcpy(word[cnt],token);//단어 배열에 분리한 단어 저장
        token = strtok(NULL,word[100]);//토큰 업데이트
        cnt ++;//
    }
    // printf("cnt = %d",cnt);
    
    for(int j=0;j<cnt;j++){//단어찾기
        max = -1;//최댓ㄱ밧 초기화
        // printf("-");
        for(int i=0;i<cnt;i++){//단어의 개수만큼 반복
            if((int)strlen(word[i])>max){ //단어의 길이가 최대인경우
                max = (int)strlen(word[i]);//최댓값 업데이트
                // printf("max = %d\n",max);
                rstnum = i;// 최대값을 가진 단어의 인덱스 저장
            }
        }
        val ++;//N과 비교할 값 업데이트
        if(val == N){//N번째 단어인경우
            printf("%s",word[rstnum]);//단어 출력
            break;//종료
        }
        strcpy(word[rstnum]," ");//단어 길이를 찾은 단어는 공백으로 초기화
        // // word[rstnum] = " ";
    }
    // printf("val %d",val);
}
//최대 N개의 단어를 포함하고 최대 길이가 M인
//영어 소문자로 이루어진 문자열을 입력받음

//단어와 단어는 공백으로 분리 됨.

//문자열에 포함된 다너들을 길이가 가장 긴 단어부터 짧은 단어까지 정렬

//K번째 위치의 단어를 출력하라.

//abc def ghi jklm opqrst