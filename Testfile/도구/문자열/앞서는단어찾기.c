#include  <stdio.h>
#include<string.h>
int main(){
    char str1[100],str2[100];
    gets(str1);
    gets(str2);
    int rst  = strcmp(str1,str2);
    if(rst<0)printf("A");
    else if(rst>0)printf("B");
    else printf("=");
    
    // printf("%c",str1[0]);
}