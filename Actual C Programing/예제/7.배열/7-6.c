#include  <stdio.h>
int main(){
    
    int score[3][2];
    double sum1 = 0,sum2 = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&score[i][j]);
            if(j==0)
                sum1 += score[i][j];
            else
                sum2 += score[i][j];
        }
    }
    printf("%lf %lf",sum1/3,sum2/3);
}
