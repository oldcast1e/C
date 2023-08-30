#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    char A[100],*pa = A,B[100],*pb = B;
    char cha[100],*pcha = cha;
    strcpy(pcha,"\0");
    char tmp[100],*ptmp = tmp;
    int N,lena,len1,cnta=0,cntcha=0;

    gets(A);
    scanf("%d",&N);
    // gets(A);
    lena = strlen(A);
    for(int i=0;i<lena;i++){
        if('A' <= *(pa+i) && *(pa+i) <= 'Z'){
            *(pcha+cntcha) = *(pa+i)- N;
            cntcha ++;
        }

        else if('a' <= *(pa+i) && *(pa+i) <= 'a'){
            *(pcha+cntcha) =*(pa+i)+ N;
            cntcha++;
        }

        else if('0' <= *(pa+i) && *(pa+i) <= '9'){
            for(int i=0;i<N;i++){
                *(pcha+cntcha) = *(pa+i)+15;
                cntcha++;
            }
        }
        else{
            *(pcha+i) = ' ';
            cntcha++;
        }

    }
    len1 = strlen(cha);
    for(int i=0;i<len1;i++){
        printf("%c",*(pcha+i));
    }

    

}
//CLikp5tGLE?Qej15J