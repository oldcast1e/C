#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,rst=0,cnt=1;
    int dnum[100][100];
    //fgets(arr, 101, stdin);
    scanf("%d",&a);
    // scanf("%s",arr);
    // for(int i=0;i<(int)strlen(arr);i++)
    //for(int i=0;i<cnt;i++)
    
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){dnum[i][j] = cnt;cnt++;}
    }

    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(i==0 || i == a-1 || j == 0 || j == a-1) rst += dnum[i][j];
        }
    }

    // for(int i=0;i<a;i++){
    //     for(int j=0;j<a;j++)printf("%d ",dnum[i][j]);
    //     printf("\n"); cnt++;
    // }
    printf("%d",rst);
    

    
} 
/*

*/