#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

void reset(char *tmp){
    for(int i=0;i<101;i++) tmp[i] = '\0';
}

int main(){
    char A[101],B[101];

    char rst[101][101];
    int rstcnt  = 0;
    for(int i=0;i<101;i++)reset(rst[i]);   
    
    gets(A);gets(B);
    int word_number1 = 0,word_number2 =0,cnt;
    int xa=0,ya=0,xb=0,yb=0;

    for(int i=0;i<(int)strlen(A);i++) if(A[i]== ' ')word_number1++;
    word_number1++;
    for(int i=0;i<(int)strlen(B);i++) if(B[i]== ' ')word_number2++;
    word_number2++;

    // printf("%d %d",word_number1,word_number2);

    char tmp[101];reset(tmp);

    char **word_A = NULL;
    word_A = (char **)malloc(word_number1*sizeof(char *));
    char **word_B = NULL;
    word_B = (char **)malloc(word_number2*sizeof(char *));
    //포인터 배열의 크기는 단어의 수와 같음
    
    //A배열
    cnt = 0;
    for(int i=0;i<(int)strlen(A);i++){
        if(A[i] != ' '){tmp[cnt] = A[i]; cnt ++;}
        if(i == (int)strlen(A)-1 || A[i] == ' '){
            int len = strlen(tmp);
            word_A[ya] = (char *)malloc(len*sizeof(char)+1);
            strcpy(word_A[ya],tmp);strcat(word_A[ya],"\0");
            ya++;cnt = 0;

            reset(tmp);
        }
    }
    //B배열
    cnt = 0;reset(tmp);
    for(int i=0;i<(int)strlen(B);i++){
        if(B[i] != ' '){tmp[cnt] = B[i]; cnt ++;}
        if(i == (int)strlen(B)-1 || B[i] == ' '){
            int len = strlen(tmp);
            word_B[yb] = (char *)malloc(len*sizeof(char)+1);
            strcpy(word_B[yb],tmp);strcat(word_B[yb],"\0");
            yb++;cnt = 0;

            reset(tmp);
        }
    }
    // 입력받은 문자열을 단어로 나누어,
    //동적으로 할당받은 두 개의 2차원 배열(포인터 배열에 연결된 문자 배열)에 각각 저장

    reset(tmp);
    for(int i=0;i<ya;i++){
        for(int j=0;j<ya;j++){
            if(i!=j){
                reset(tmp);
                strcpy(tmp,word_A[i]);strcat(tmp,word_A[j]);
                for(int k=0;k<yb;k++){
                    if(strcmp(word_B[k],tmp)==0){
                        // printf(">>>%s",tmp);
                        strcpy(rst[rstcnt],tmp);strcat(rst[rstcnt],"\0");
                        rstcnt++;
                        strcpy(word_B[k],"-1");strcat(word_B[k],"\0");
                    }
                }
            }
            
        }
    }
    for(int i=0;i<rstcnt;i++){
        for(int j=0;j<rstcnt-1;j++){
            if(strlen(rst[j]) < strlen(rst[j+1])){
                reset(tmp);
                strcpy(tmp,rst[j]);reset(rst[j]);
                strcpy(rst[j],rst[j+1]);strcat(rst[j],"\0");
                strcpy(rst[j+1],tmp);strcat(rst[j+1],"\0");
            }
            else if(strlen(rst[j]) == strlen(rst[j+1])){
                if(strcmp(rst[j],rst[j+1])>0){
                    reset(tmp);
                    strcpy(tmp,rst[j]);reset(rst[j]);
                    strcpy(rst[j],rst[j+1]);strcat(rst[j],"\0");
                    strcpy(rst[j+1],tmp);strcat(rst[j+1],"\0");
                }
            }
        }
    }
    //출력 순서는 길이가 가장 긴 단어 부터 짧은 단어까지 정렬하여 출력
    //길이가 같은 단어는 사전 순서상 빠른 단어부터 출력
    
    //printf(">%s\n",rst[i]);
    for(int i=0;i<rstcnt;i++)printf("%s\n",rst[i]);

    /**
        for(int i=0;i<ya;i++) printf(">%s\n",word_A[i]);
        printf("-------------------------\n");
        for(int i=0;i<yb;i++) printf(">%s\n",word_B[i]);
     */
    

    //포인터 배열의 크기는 단어의 수와 같아야 하며, 포인터 배열에 연결되는 각 문자 배열은 단어의 길이+1의 크기

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




