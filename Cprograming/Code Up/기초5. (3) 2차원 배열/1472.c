#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=1;
    int num[100];
    int dnum[100][100];
    //fgets(arr, 101, stdin);
    scanf("%d %d",&a,&b);
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){dnum[i][j] = cnt;cnt++;}
        // printf("\n"); 
    }

    for(int i=a-1;i>=0;i--){
        if(i%2==0)for(int j=b-1;j>=0;j--){printf("%d ",dnum[i][j]);}
        else {for(int j=0;j<b;j++){printf("%d ",dnum[i][j]);}}
        printf("\n"); 
    }
    

    
} 
/*

*/