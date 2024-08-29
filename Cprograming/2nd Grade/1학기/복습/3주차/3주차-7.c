#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count(char *arr,char c, int k, int *cnt){
    if(k >= 0){
        if(arr[k] == c) *cnt += 1;
        return count(arr,c,k-1,cnt);
    }
    return *cnt;
}

int main(){
    char arr[100],c; scanf("%s",arr); getchar();
    int len = strlen(arr),cnt = 0;
    scanf("%c",&c);
    printf("%d",count(arr,c,len-1,&cnt));
} 
/*
sheIsASsudens
s
*/