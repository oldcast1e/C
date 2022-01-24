#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    char str1[101],*pstr1= str1;
    char str2[101],*pstr2= str2;
    gets(str1);gets(str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int key,rst =0;

    for(int i=0;i<len1;i++){
        key = 0;
        if(*(pstr1+i)==*pstr2){
            for(int j=0;j<len2;j++){
                if(*(pstr1+i+j) == *(pstr2+j)) key ++;
            }
            if(key == len2) rst ++;
        }
    }
    printf("%d",rst);

}