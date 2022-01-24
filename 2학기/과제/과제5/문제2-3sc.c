#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

void reset(char *tmp){//배열 초기화 함수
    for(int i=0;i<101;i++) tmp[i] = '\0';
}

int main(){//메인함수
    char A[101],B[101];
    //두개의 배열 선언
    char rst[101][101];//결과를 저장할 배열 선언
    int rstcnt  = 0;//결과 매개변수
    for(int i=0;i<101;i++)reset(rst[i]);   //결과배열을 초기화
    
    gets(A);gets(B);//두 배열을 입력받음
    int word_number1 = 0,word_number2 =0,cnt;
    //배열 A,B에서 단어의 개수를 저장할 변수 선언 및 매개변수 cnt선언
    int xa=0,ya=0,xb=0,yb=0;//배열 A,B의 인덱스

    for(int i=0;i<(int)strlen(A);i++) if(A[i]== ' ')word_number1++;
    word_number1++;//배열 A의 단어개수 구하기
    for(int i=0;i<(int)strlen(B);i++) if(B[i]== ' ')word_number2++;
    word_number2++;//배열 B의 단어개수 구하기


    char tmp[101];reset(tmp);//임의의 배열 tmp선언 및 초기화

    char **word_A = NULL;
    word_A = (char **)malloc(word_number1*sizeof(char *));//A의 단어를 저장할 배열 동적할당
    char **word_B = NULL;
    word_B = (char **)malloc(word_number2*sizeof(char *));//B의 단어를 저장할 배열 동적할당

    cnt = 0;//매개변수 초기화
    for(int i=0;i<(int)strlen(A);i++){//배열 A의 길이만큼 바놉ㄱ
        if(A[i] != ' '){tmp[cnt] = A[i]; cnt ++;}//공백이 아니면 임의의 배열에 해당 요소저장하고 매개변수 업데이트
        if(i == (int)strlen(A)-1 || A[i] == ' '){//공백이거나 마지막 자리이면
            int len = strlen(tmp);//단어의 길이를 구하고
            word_A[ya] = (char *)malloc(len*sizeof(char)+1);//동적할당 후
            strcpy(word_A[ya],tmp);strcat(word_A[ya],"\0");//저장
            ya++;cnt = 0;//매개변수 업데이트

            reset(tmp);//임의의 값 tmp 초기화
        }
    }
    cnt = 0;reset(tmp);//매개변수 초기화/임의의 값 tmp 초기화
    for(int i=0;i<(int)strlen(B);i++){//배열 B의 길이만큼 바놉ㄱ
        if(B[i] != ' '){tmp[cnt] = B[i]; cnt ++;}//공백이 아니면 임의의 배열에 해당 요소저장하고 매개변수 업데이트
        if(i == (int)strlen(B)-1 || B[i] == ' '){//공백이거나 마지막 자리이면
            int len = strlen(tmp);//단어의 길이를 구하고
            word_B[yb] = (char *)malloc(len*sizeof(char)+1);//동적할당 후
            strcpy(word_B[yb],tmp);strcat(word_B[yb],"\0");//저장
            yb++;cnt = 0;

            reset(tmp);//임의의 값 tmp 초기화
        }
    }
    reset(tmp);//임의의 값 tmp 초기화
    for(int i=0;i<ya;i++){//A의 단어의 개수만큼 반복
        for(int j=0;j<ya;j++){//A의 단어의 개수만큼 반복
            if(i!=j){
                reset(tmp);//임의의 값 tmp 초기화
                strcpy(tmp,word_A[i]);strcat(tmp,word_A[j]);//임의의 배열에 해당 단어를 저장
                for(int k=0;k<yb;k++){//B의 단어 개수만큼 반복하여
                    if(strcmp(word_B[k],tmp)==0){//동일한 단어가 있으면
                        strcpy(rst[rstcnt],tmp);strcat(rst[rstcnt],"\0");//결과 배열에저장
                        rstcnt++;//결과 매개변수 증가
                        strcpy(word_B[k],"-1");strcat(word_B[k],"\0");//확인한 B단어를 -1로 변환
                    }
                }
            }
            
        }
    }
    for(int i=0;i<rstcnt;i++){//결과 단어 개수만큼 반복
        for(int j=0;j<rstcnt-1;j++){//버블 정렬
            if(strlen(rst[j]) < strlen(rst[j+1])){//길이 순으로 정렬
                reset(tmp);////임의의 값 tmp 초기화
                strcpy(tmp,rst[j]);reset(rst[j]);
                strcpy(rst[j],rst[j+1]);strcat(rst[j],"\0");//정렬
                strcpy(rst[j+1],tmp);strcat(rst[j+1],"\0");
            }
            else if(strlen(rst[j]) == strlen(rst[j+1])){//길이가 같으면
                if(strcmp(rst[j],rst[j+1])>0){//사전순으로 정렬
                    reset(tmp);//임의의 값 tmp 초기화
                    strcpy(tmp,rst[j]);reset(rst[j]);
                    strcpy(rst[j],rst[j+1]);strcat(rst[j],"\0");//정렬
                    strcpy(rst[j+1],tmp);strcat(rst[j+1],"\0");
                }
            }
        }
    }
    for(int i=0;i<rstcnt;i++)printf("%s\n",rst[i]);//결과출력
}



