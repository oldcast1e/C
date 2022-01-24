#include  <stdio.h>
int main(){

    int n,num,cnt;
    int same=0,lag=0,sma=0;
    scanf("%d",&n);
    while(1){
        scanf("%d",&num);
        cnt = 0;
        if(num==0){
            break;
        }
        else{
            while(num>0){
                cnt = num%10;
                if(cnt==n)
                    same +=1;
                else if(cnt>n)
                    lag +=1;
                else if(cnt<n)   
                    sma +=1;
                num/=10;
            }
        }
    }
    printf("%d %d %d",same,sma,lag);
}