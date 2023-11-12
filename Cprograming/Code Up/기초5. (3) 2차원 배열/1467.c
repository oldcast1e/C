#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=1;
    int dnum[100][100];
    scanf("%d %d",&a,&b);
    // scanf("%s",arr);
    // for(int i=0;i<(int)strlen(arr);i++)
    

    for(int i=0;i<a;i++){
        cnt = i+1;
        for(int j=0;j<b;j++){
            dnum[i][j]=cnt;
            cnt += a;
            // printf("%d ",cnt); 
        }
    }

    for(int i=0;i<a;i++){
        cnt = i+1;
        for(int j=b-1;j>=0;j--){
            printf("%d ",dnum[i][j]); 
        }printf("\n");
    }

    
} 
/*
3 4

1 2 3 4
5 6 7 8
9 10 11 12

1 4 7 10 //4 
2 5 8 11
3 6 9 12
//3

1 2 3
4 5 6
7 8 9
10 11 12

10 7 4 1
11 8 5 2
12 9 6 3

*/