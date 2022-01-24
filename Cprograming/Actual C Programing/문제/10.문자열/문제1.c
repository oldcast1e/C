#include  <stdio.h>
#include <string.h>
int main(){

    char arr[20],*parr = arr;
    gets(arr);
    int len = strlen(arr);
    // printf("%d",len);
    for(int i=0;i<len;i++){
        if(97<=*(parr+i) && *(parr+i)<=122) printf("%c",*(parr+i));
    }



}