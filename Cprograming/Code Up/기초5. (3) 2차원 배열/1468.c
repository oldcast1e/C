#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,n,m,cnt=1;
    int num[1000][1000];

    scanf("%d",&a);
    for(int i=0;i<a;i++)
        for(int j=0;j<a;j++) {num[i][j] = cnt;cnt++;};

    for(int i=0;i<a;i++){
        if(i%2==0){
            for(int j=0;j<a;j++)printf("%d ",num[i][j]);
            printf("\n");
        }
        else {
            for(int j=a-1;j>=0;j--)printf("%d ",num[i][j]);
            printf("\n");
        }  
    } 
} 

/*
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

1 5 9 13 
2 6 10 14 
3 7 11 15 
4 8 12 16 
*/