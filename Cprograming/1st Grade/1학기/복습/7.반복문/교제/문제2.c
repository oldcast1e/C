#include  <stdio.h>
int main(){
    
    int n,cnt=0;
    int sum=0,max,min;
    while (1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        if(cnt==0){
            max = n;
            min = n;
        }
        cnt ++;

        sum +=n;
        if(n>max)
            max = n;
        if(n<min)
            min = n;        

    }
    printf("%d %d %d",sum,min,max);
    

}
