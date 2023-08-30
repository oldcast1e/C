#include  <stdio.h>
int main(){

    int n,num;
    int same=0,lag=0,sma=0;
    scanf("%d",&n);
    while(1){
        scanf("%d",&num);
        if(num==0){
            break;
        }
        else{
            if(num==n)
                same +=1;
            else if(num>n)
                lag +=1;
            else    
                sma +=1;
        }
    }
    printf("%d %d %d",same,sma,lag);
}