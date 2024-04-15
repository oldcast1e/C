#include  <stdio.h>

int main(){

    int n;
    int sn,score[1000],cnt;

    double sum,avg;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        cnt = 0;
        sum = 0;

        scanf("%d",&sn);
        for(int j=0;j<sn;j++){
            scanf("%d",&score[j]);
            sum += score[j];
        }
        // printf("sum: %.3f",sum);
        avg = sum/(double)sn;
        for(int j=0;j<sn;j++){
            if((double)score[j]>avg) cnt++;
        }
        printf("%.3f%%\n",(double)cnt/(double)sn*100);

    }
}