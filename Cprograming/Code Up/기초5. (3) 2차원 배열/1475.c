#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,n=0,d,cnt=1;
    int dnum[100][100];
    //fgets(arr, 101, stdin);
    scanf("%d %d",&a,&b);
    for(int i=0;i<b;i++){
        for(int j=a-1;j>=0;j--){
            dnum[j][i] = cnt; 
            cnt++;
        }
        // printf("\n"); 
    }
    //b가 짝수이면 첫번째 부터 반전
    //b가 홀수면 첫번째는 그대로


    for(int i=0;i<a;i++){
        for(int j=b-1;j>=0;j--){
    
            if(j%2!=0)printf("%d ",dnum[i][j]);
            else if(j%2==0) printf("%d ",dnum[a-1-i][j]);
        }
        printf("\n"); 
    }
    // printf("-------------원본-------------\n");
    // for(int i=0;i<a;i++){
    //     for(int j=0;j<b;j++)printf("%d ",dnum[i][j]);
    //     printf("\n"); cnt++;

    // }
}