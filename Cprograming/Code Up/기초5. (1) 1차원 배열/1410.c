#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int r=0,l=0;

    char arr[100000];
    scanf("%s",arr);
    for(int i=0;i<(int)strlen(arr);i++){
        if(arr[i]=='(')l++;
        else if(arr[i]==')')r++;
    }printf("%d %d",l,r);
} 
/*

*/#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int r=0,l=0;

    char arr[100000];
    scanf("%s",arr);
    for(int i=0;i<(int)strlen(arr);i++){
        if(arr[i]=='(')l++;
        else if(arr[i]==')')r++;
    }printf("%d %d",l,r);
} 
/*

*/