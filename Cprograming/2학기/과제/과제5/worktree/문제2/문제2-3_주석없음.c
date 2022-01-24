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


    char tmp[101];reset(tmp);

    char **word_A = NULL;
    word_A = (char **)malloc(word_number1*sizeof(char *));
    char **word_B = NULL;
    word_B = (char **)malloc(word_number2*sizeof(char *));
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
    reset(tmp);
    for(int i=0;i<ya;i++){
        for(int j=0;j<ya;j++){
            if(i!=j){
                reset(tmp);
                strcpy(tmp,word_A[i]);strcat(tmp,word_A[j]);
                for(int k=0;k<yb;k++){
                    if(strcmp(word_B[k],tmp)==0){
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
    for(int i=0;i<rstcnt;i++)printf("%s\n",rst[i]);
}



