#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
void reset(char *str){
    for(int i=0;i<100;i++)str[i] = '\0';
}

int main(){

    int N,num[101],cnt;
    for(int i=0;i<101;i++)num[i] = 0;
    char X[101],arr[101];

    char tmp[101];
    
    scanf("%d %s",&N,X);getchar();
    //문자형 포인터 배열 Y
    char *Y[101]={};
    for(int i=0;i<N;i++){
        reset(arr);gets(arr);
        Y[i] = (char*)malloc((int)strlen(arr)*sizeof(char)+1);
        if(Y[i]== NULL){
            printf("Error");
            return -1;
        }
        // 동적 할당 시 정상적으로 메모리 할당이 되었는지를 체크
        strcpy(Y[i],arr);strcat(Y[i],"\0");
        //Y를 동적할당

        reset(tmp);strcpy(tmp,Y[i]);strcat(tmp,"\0");
        for(int j=0;j <= ((int)strlen(Y[i])-(int)strlen(X));j++){//13-3=10
            cnt = 0;
            if(tmp[j] == X[0]){//첫번째 비교 대상이 같으면
                for(int k=0;k<(int)strlen(X);k++){
                    //배열 X의 길이 만큼 반복
                    if(tmp[j+k] == X[k])cnt ++;
                    if(cnt == (int)strlen(X)){
                        num[i] +=1;
                        tmp[j+k] = ' ';
                    }
                }     
            }
        }
        // printf("num[%d] = %d\n",i,num[i]);
    }
    // for(int i=0;i<N;i++) printf("num[%d] = %d\n",i,num[i]);


    int max =0 ;
    char rst[101];
    char beforerst[101];reset(beforerst);
    for(int i=0;i<(int)strlen(X);i++){
        if(i==0){ 
            max = num[i];
            reset(rst);
            strcpy(beforerst,Y[i]);strcat(beforerst,"\0");
            strcpy(rst,Y[i]);strcat(rst,"\0");
        }
        else{
            if(num[i] > max){
                max = num[i];
                reset(rst);
                strcpy(rst,Y[i]);strcat(rst,"\0");
            }
        }
    }
    if(max !=0){
        printf("%s",rst);
        // if(strcmp(rst,beforerst)!=0)printf("\n%s",beforerst);
    }
    else printf("NONE");

    for(int i=0;i<N;i++)free(Y[i]);

    //동적으로 할당 받은 메모리 해제
}
/*
3 abc
abcabc abcabc
ABCabc ABCabc
abc abc abc abcd

abcabc abcabc
ABCabcabcABCabcabc
abc abc abc abcd

3 aaa
aaaaaa aaa aaaa
aaa aaa aaa
aaaaa aaaaa aaaaa

3 abc
ab cab c abd
ABCab cABC
a bca bca bcd
*/