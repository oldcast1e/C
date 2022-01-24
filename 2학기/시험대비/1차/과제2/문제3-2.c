#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    char str1[101],*pstr1= str1;
    char str2[101],*pstr2= str2;

    char word[100][100];
    gets(str1);gets(str2);
    int len1 = strlen(str1),a=0,b=0;

    for(int i=0;i<len1;i++){
        if(*(pstr1+i)!=' '){
            word[a][b] = *(pstr1+i);
            b++;
        }
        else{
            a++;
            b=0;
        }
    }
    int len2 = strlen(str2);
    int key,rst =0;

    for(int i=0;i<=a;i++){
        if(strncmp(word[i],str2,len2)==0) rst++;
    }
    printf("%d",rst);

}