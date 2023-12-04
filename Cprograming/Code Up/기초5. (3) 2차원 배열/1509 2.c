#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    int rst[10]={0};
    int dnum[11][11];
   
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)scanf("%d",&dnum[i][j]);
    }
    for(int i=0;i<10;i++)scanf("%d",&dnum[10][i]);
    
    
    
    // printf("--------------\n");
    // for(int i=0;i<11;i++){
    //     if(i==10)printf("--------------\n");
    //     for(int j=0;j<10;j++)printf("%d ",dnum[i][j]);
    //     printf("\n");
    // }
    // printf("--------------\n");

    for(int j=0;j<10;j++){
        for(int i=9;i>=0;i--){
            if(dnum[i][j] < 0){rst[j] = -1;
                            // printf("%d번째 말 빠짐!\n",j+1);break;
                              }
            else if (dnum[i][j] > 0){rst[j] = 1;
                            // printf("%d번째 말 부딪힘!\n",j+1);
                                     break;}
            else rst[j] = 0;
        }
    }
    for(int i=0;i<10;i++){
        if(dnum[10][i]==1){
            printf("%d ",i+1);
            switch (rst[i]) {
                case -1:
                    printf("fall\n"); break;
                case 0 : 
                    printf("safe\n"); break;
                case 1:
                    printf("crash\n"); break;
            }
        }
    }
    
} 
/*

*/