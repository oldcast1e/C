#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char arr[1001];
    scanf("%s",arr);
    for(int i=0;i<(int)strlen(arr);i++){
        if('a'<=arr[i] && arr[i] <= 'z') printf("%c",arr[i]-32);
        else if('A'<=arr[i] && arr[i] <= 'Z') printf("%c",arr[i]+32);
        else  printf("%c",arr[i]);
    }
 
} 
