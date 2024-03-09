#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void move(char *arr){
    int len = (int)strlen(arr);
    char tmp = arr[0];
    for(int i=1;i<len;i++)arr[i-1] = arr[i];
    arr[len-1] = tmp;
}
int main(){
    char arr[100];  scanf("%s",arr);
    int len = (int)strlen(arr);
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++)printf("%c",arr[j]); 
        printf("\n");
        
        move(arr);
    }
    // printf("l = %d\n",len);
    // for(int j=0;j<len;j++)printf("%c",arr[j]); 
    
} 
/*
abcde
*/