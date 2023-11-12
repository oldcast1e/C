#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    char arr[10];
    //fgets(arr, 101, stdin);
    scanf("%s",arr);
    for(int i=0;i<(int)strlen(arr);i++){
        if(arr[i]=='t') printf("%d ",i+1);
    }
} 
/*

*/