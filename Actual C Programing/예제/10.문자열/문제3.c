#include  <stdio.h>
int main(){

    char *pchar = "To be, or not to be : that is the question";
    int cnt= 0,n=0;
    while(1){
        if(*(pchar+n)=='\0') break;
        if(*(pchar+n)=='t') cnt ++;
        n++;
    }
    printf("문자열 \"To be, or not to be : that is the question\"에 문자 t가 %d번 나타남",cnt);
} 