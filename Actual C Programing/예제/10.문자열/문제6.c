#include  <stdio.h>
#include <string.h>
int main(){

    char A[21],B[21],C[61];
    scanf("%s %s",A,B);
    printf("%d %d\n",(int)strlen(A),(int)strlen(B));
    printf("%s\n",strcmp(A,B)>0?B:A);
    strcpy(C,A);
    strcat(C,B);
    strcat(C,A);
    printf("%s",C);
    
//welcome helloworld!!
}