#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    char arr[100];
    float n1,n2;
    fgets(arr, 101, stdin);
    // scanf("%d",&a);
    // scanf("%s",arr);
    for(int i=0;i<(int)strlen(arr);i++){
        if((i+3)<(int)strlen(arr)){
            if(arr[i]=='l' && arr[i+1]=='o' && arr[i+2]=='v' && arr[i+3]=='e') cnt ++;
        }
    }
    printf("%d",cnt);
} 
/*

*/