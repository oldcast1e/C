#include  <stdio.h>
#include<string.h>
int main(){
    int N,min=102,len;
    char str[100],tmp[100],rst[100];
    char delim[] = " ,\n";
    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++){
        strcpy(str,"");//입력받을 문자열(배열)초기화
        strcpy(tmp,"");//입력받을 문자열(배열)초기화

        scanf("%[^\n]%*c",str);
        // char *token = strtok(str,delim);
        // while(token != NULL){
        //     strcat(tmp,token);
        //     token = strtok(NULL,delim);
        // }
        len = strlen(str);
        if(len<min){
            min = len;
            strcpy(rst,"");
            strcat(rst,str);
        }
    }
    printf("%s",rst);
}