#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int min(int a,int b){
    return(a>b?b:a);
}
int main(){
    int n,cnt=0;
    int num[100];
    scanf("%d",&n);
    // for(int i=0;i<(int)strlen(arr);i++)
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    for(int k=0;k<n/2;k++){
        num[k] = min(num[2*k], num[2*k+1]);
        printf("%d ",num[k]);
        //m[k] = min(m[2*k], m[2*k+1]); //k >= 0
    }
    /*
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++)printf("%d ",dnum[i][j]);
        printf("\n"); cnt++;
    }
    */
    

    
} 
/*
6
1 3 5 6 4 2 
*/