#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=1;
    int darr[1000][1000];

    scanf("%d",&a);
    for(int i=0;i<a;i++)
        for(int j=0;j<a;j++) {darr[i][j] = cnt;cnt++;};
    
    for(int i=0;i<a;i++){
        for(int j=a-1;j>=0;j--)printf("%d ",darr[i][j]);
        printf("\n");
    }

    
} 