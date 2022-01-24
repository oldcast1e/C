#include  <stdio.h>
int main(){

    int n[5];
    double sum=0,avg=0;
    for(int i=0;i<5;i++){
        scanf("%d",&n[i]);
        sum += n[i];
    }    
    printf("%lf %lf",sum,sum/5);
}
