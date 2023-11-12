#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,n,m,cnt=1;
    int dnum[100][100];

    scanf("%d",&a);
    for(int i=0;i<a;i++){
        cnt = i+1;
        for(int j=0;j<a;j++) {dnum[i][j] = cnt;cnt+=a;}
    }

    // for(int i=0;i<a;i++){
    //     for(int j=0;j<a;j++)printf("%d ",dnum[i][j]);
    //     printf("\n"); cnt++;
    // }

    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(j%2==1){
                printf("%d ",dnum[a-1-i][j]);
            }
            else printf("%d ",dnum[i][j]);
        }printf("\n");
    }

} 