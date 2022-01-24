#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct st{//구조체 정의
    char *str; // 문자열 저장 
    int cnt1; // 자음 수 저장 
    int cnt2; // 모음 수 저장
    int num;
    int result1; // 곱셈결과 저장 
    int result2; // 곱셈결과 저장
    //result1가 result2보다 더 크게 설정할 것임
};

int main(){
    
    int N;//입력받을 정수
    char word[101];//입력받을 배열
    scanf("%d",&N);getchar();//정수를 입력받음

    struct st *val = NULL;
    val  = (struct st*)malloc(sizeof(struct st)*N);//구조체 동적할당
    if( val == NULL){//에러확인
        printf("Error");
        return -1;
    }//에러 확인
    // 구조체 배열과 문자열을 저장 할 배열은 동적으로 할당 받아 사용
    //문자열을 저장 할 배열의 크기는 문자개수+1
    for(int i=0;i<N;i++){//입력받은 정수만큼 반복
        gets(word);//배열 초기화 및 배열 입력받음
        val[i].str = NULL;
        val[i].str  = (char *)malloc(sizeof(char)*strlen(word)+1);//구조체 멤버 동적할당
        if( val[i].str == NULL){//에러확인
            printf("Error");
            return -1;
        }   //에러 확인
        // printf("size[%d] = %d | len = %d\n",i,(int)sizeof(char)*(int)strlen(word)+1,(int)strlen(word));
        strcpy(val[i].str,word);

        for(int j=0;j<strlen(val[i].str);j++){//배열의 길이만큼 반복
            if(val[i].str[j] == 'a' || val[i].str[j] == 'e'|| val[i].str[j] == 'i'|| val[i].str[j] == 'o'|| val[i].str[j] == 'u'){
                val[i].cnt2 ++;//모음
            }
            else if(val[i].str[j] == 'A' ||val[i].str[j] == 'E'||val[i].str[j] == 'I'||val[i].str[j] == 'O'||val[i].str[j] == 'U'){
                val[i].cnt2 ++;//모음
            }
            else if(('a'<= val[i].str[j] && val[i].str[j] <= 'z') || ('A'<= val[i].str[j] && val[i].str[j] <= 'Z')){
                val[i].cnt1 ++;//자음
            }
            else if('0'<=val[i].str[j] && val[i].str[j] <= '9'){
                val[i].num = val[i].str[j] - '0';//숫자
            }
        }
        val[i].result1 = val[i].num* val[i].cnt1;//곱셈결과 1
        val[i].result2 = val[i].num* val[i].cnt2;//곱셈결과 2

        if(val[i].result1<val[i].result2){//곱셈결과 중 큰 값을 result1로 변환
            int tmp = val[i].result1;
            val[i].result1 = val[i].result2;
            val[i].result2 = tmp;
        }
    }
    //문자열에 포함된 한 개의 숫자와 자음 의 수와 모음의 수 중 
    //큰 수의 곱이 가장 큰 문자열부터 내림차순으로 정렬
    for (int i = 0; i < N; i++) {//N번 반복
      for (int j = 0; j < N-1; j++) {///N번 반복
            if (val[j].result1 < val[j+1].result1) {//자음의 개수에 따라 변경
               struct st tmp;//임의 구조체 선언
               tmp = val[j];
               val[j] = val[j+1];
               val[j+1] = tmp;//스왑
            }
            else if (val[j].result1 == val[j+1].result1) {//자음의 수가 같은 경우
               if (val[j].result2 < val[j+1].result2) {//모음의 수 살피기
                  struct st tmp;//임의의 구조체 
                  tmp = val[j];
                  val[j] = val[j+1];
                  val[j+1] = tmp;//스왑
               }
            }
         
      }
   }
    for(int i=0;i<N;i++)printf("%s\n",val[i].str);//결과출력
    for(int i=0;i<N;i++) free(val[i].str);
    free(val);
    
    return 0;
}

/*
5
His0tory
3Politics
2DonQuixote
LaPest9e
Chaos5
*/
