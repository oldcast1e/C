#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char arr[20];
    scanf("%s",arr);
    for(int i=0;i<(int)strlen(arr);i++){
        printf("\'%c\'\n",arr[i]);
    }
}