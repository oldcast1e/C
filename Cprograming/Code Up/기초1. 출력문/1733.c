#include<stdio.h>
#include<string.h>
int main(){
    char str1[100],*str2 = "IOI";
    scanf("%s",str1);
    int check = strcmp(str1,str2);
    if(check == 0)printf("IOI is the International Olympiad in Informatics.");
    else printf("I don't care.");
  
    //printf("%d",(int)strcmp(str1,str2));
}