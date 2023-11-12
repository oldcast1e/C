#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=1;
    int num[100];
    char arr[100];
    float n1,n2;
    //fgets(arr, 101, stdin);
    scanf("%d",&a);
    // scanf("%s",arr);
    // for(int i=0;i<(int)strlen(arr);i++)
    for(int i=1;i<=a;i++){
        cnt = 0;
        for(int j=0;j<a;j++){printf("%d ",i+cnt);cnt += a;}
        printf("\n");
    }
    // scanf("%d %d %d %d",&a,&b,&c,&d);
    
    //printf("%d",'b'-'a');
    
} 
/*
1 4 7
2 5 8
3 6 9
*/