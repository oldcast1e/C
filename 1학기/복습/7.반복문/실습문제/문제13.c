#include  <stdio.h>
int main(){
    
    int n,cnt=0;
    double sum=0,avg=0;
    while(1){

        scanf("%d",&n);
        if(n<=0)
            break;
        
        if(n<100){
            cnt++;
            sum += n;
        }
    }
    avg = sum/cnt;
    printf("%.0lf %.2lf %d",sum,avg,cnt);

}
