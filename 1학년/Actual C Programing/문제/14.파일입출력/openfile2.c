#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    char str[100],rst[100];
    int a,b,c;
    FILE *f1,*f2,*f3;

    f1 = fopen("/Users/apple/Desktop/C/Actual C Programing/문제/14.파일입출력/user_input","w");
    
    fgets(str,20,stdin);
    fprintf(f1,"%s",str);
    fclose(f1);

    f2 = fopen("/Users/apple/Desktop/C/Actual C Programing/문제/14.파일입출력/user_input","r");
    fgets(rst,20,f2);
    printf("result string is %s",rst);


    fclose(f2);

}
// 21011898 kimpowe 20
// 21012352 gildong 21
// 21023214 kimnamu 20