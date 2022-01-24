#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    char str[1001],*pstr= str;
    gets(str);
    int len = strlen(str),cnt=-1;
    // printf("%d",len);
    int num = len -1; //소문자부터

    for(int i=num;i>=0;i--){
        if(i==0){
            for(int j=0;j<=cnt;j++){
                printf("%c",*(pstr+i+j));
            }
            printf("%c",*(pstr+num));
        }

        else if(*(pstr+i)!=' ') cnt ++;
        
        else{
            for(int j=1;j<=cnt;j++){
                printf("%c",*(pstr+i+j));
            }
            cnt = 0;
            printf(" ");
        }
    }

    //you can cage a swallow can't you?


}