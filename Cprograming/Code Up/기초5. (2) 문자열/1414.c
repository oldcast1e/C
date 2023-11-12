#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n=0,m=0;
    char arr[100];
    //fgets(arr, 101, stdin);
    scanf("%s",arr);
    for(int i=0;i<(int)strlen(arr);i++){
        if(arr[i] == 'C' || arr[i] == 'c') n ++;
        if(i < (int)strlen(arr)-1 ){
            if((arr[i] == 'C' || arr[i] == 'c') && (arr[i+1] == 'C' || arr[i+1] == 'c'))
                m ++;
        }
    }
    // scanf("%d %d",&a,&b);
    // scanf("%d %d %d",&a,&b,&c);
    // scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%d\n%d",n,m);
    //for(int i=0;i<cnt;i++)
} 
/*

*/