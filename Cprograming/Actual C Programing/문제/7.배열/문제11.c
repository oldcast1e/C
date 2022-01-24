#include  <stdio.h>
int main(){

    int score[3][2],cnt=0;
    double sum[2]={0,};

    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&score[i][j]);
            if(j==0)
                sum[0]+= score[i][j];
            else    
                sum[1] += score[i][j];
        }
    }

    for(int i=0;i<3;i++){
        if(cnt!=0)
                printf("\n");
            cnt++;
        for(int j=0;j<2;j++){
            if((double)score[i][j]<sum[j]/3)
                printf("%d ",score[i][j]);
        }
    }


    

}


