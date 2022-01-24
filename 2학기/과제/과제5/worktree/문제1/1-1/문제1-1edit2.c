#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct st{//구조체 정의
    char *str; // 문자열 저장 
    int cnt1; // 자음 수 저장 
    int cnt2; // 모음 수 저장
};

void reset(char *str){//
    for(int i=0;i<101;i++) str[i] = '\0';
}

int main(){
    
    int N;
    char word[101];
    scanf("%d",&N);getchar();

    struct st *val = NULL;
    val  = (struct st*)malloc(sizeof(struct st)*N);
    if( val == NULL){
        printf("Error");
        return -1;
    }//에러 확인
    // 구조체 배열과 문자열을 저장 할 배열은 동적으로 할당 받아 사용
    //문자열을 저장 할 배열의 크기는 문자개수+1
    for(int i=0;i<N;i++){
        reset(word);gets(word);
        val[i].str = NULL;
        val[i].str  = (char *)malloc(sizeof(char)*strlen(word)+1);
        if( val[i].str == NULL){
            printf("Error");
            return -1;
        }   //에러 확인
        // printf("size[%d] = %d | len = %d\n",i,(int)sizeof(char)*(int)strlen(word)+1,(int)strlen(word));
        strcpy(val[i].str,word);
        strcat(val[i].str,"\0");
        //각 문자열에 포함된 자음의 수와 모음의 수를 세어
        for(int j=0;j<strlen(val[i].str);j++){
            if(val[i].str[j] == 'a' || val[i].str[j] == 'e'|| val[i].str[j] == 'i'|| val[i].str[j] == 'o'|| val[i].str[j] == 'u'){
                val[i].cnt2 ++;//모음
            }
            else if(val[i].str[j] == 'A' ||val[i].str[j] == 'E'||val[i].str[j] == 'I'||val[i].str[j] == 'O'||val[i].str[j] == 'U'){
                val[i].cnt2 ++;//모음
            }
            else if(('a'<= val[i].str[j] && val[i].str[j] <= 'z') || ('A'<= val[i].str[j] && val[i].str[j] <= 'Z')){
                val[i].cnt1 ++;//자음
            }
        }
    }
    for (int i = 0; i < N; i++) {//N번 반복
      for (int j = 0; j < N-1; j++) {///N번 반복
            if (val[j].cnt1 < val[j+1].cnt1) {//자음의 개수에 따라 변경
               struct st tmp;//임의 구조체 선언
               tmp = val[j];
               val[j] = val[j+1];
               val[j+1] = tmp;//스왑
            }
            else if (val[j].cnt1 == val[j+1].cnt1) {//자음의 수가 같은 경우
               if (val[j].cnt2 < val[j+1].cnt2) {//모음의 수 살피기
                  struct st tmp;//임의의 구조체 
                  tmp = val[j];
                  val[j] = val[j+1];
                  val[j+1] = tmp;//스왑
               }
            }
         
      }
   }
    for(int i=0;i<N;i++)printf("%s\n",val[i].str);//결과출력
    // for(int i=0;i<N;i++)printf("%s| cnt1 : %d cnt2 : %d | len : %d\n",val[i].str,val[i].cnt1,val[i].cnt2,(int)strlen(val[i].str));//결과출력
    for(int i=0;i<N;i++) free(val[i].str);
    free(val);
    
    return 0;
}

/*
정수 N을 입력 받고, 공백을 포함하지 않은 N개의 문자열을 입력 받 아, 
각 문자열에 포함된 자음의 수와 모음의 수를 세어, 

자음의 수가 가장 많은 문자열부터 내림 차순으로 정렬 한 후 순서대로 문자열을 출력하고,
만약 자음의 수가 같은 문자열에 대해서는 모 음의 수가 가장 많은 문자열부터 출력하는 프로그램

- 자음의 수와 모음의 수가 같은 문자열이 있는 경우에는 입력된 순서대로 출력 하시오.
- 문자열의 최대 길이는 100 이며, 문자열은 영문 대문자와 소문자로 이루어진다.
- 다음과 같은 구조체를 정의해서 사용하고, 구조체 배열과 문자열을 저장 할 배열은 동적으로 할당 받아 사용하고 , 
프로그램 종료 시 할당된 메모리는 반드시 해제한다.

- 문자열을 저장 할 배열의 크기는 문자개수+1 (위반 시 30% 감점)
History
Politics 
DonQuixote
LaPeste
Chaos
*/