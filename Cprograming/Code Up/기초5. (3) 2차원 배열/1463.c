#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=1;
    int num[1000][1000];

    scanf("%d",&a);
    for(int i=0;i<a;i++)
        for(int j=0;j<a;j++) {num[i][j] = cnt;cnt++;};
    
    cnt = a-1;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++)printf("%d ",num[j][cnt]);
        printf("\n"); cnt--;
    }

    
} 
/*
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/