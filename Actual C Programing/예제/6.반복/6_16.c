#include  <stdio.h>
int main() 
{
    int n=2,k,i,cnt=0;
    while(n<=50){
        k=0;
        for(i=2;i<=n-1;i++){
            if(n%i==0)
                k ++;
        }
        if(k==0){
            printf("%d ",n);
            cnt++;
            if(cnt%5==0)
                printf("\n");

        }
        n++;
    }

}