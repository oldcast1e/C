#include  <stdio.h>
int main() 
{
    int N,n,sum=0;
    scanf("%d",&N);

    int R = N;
    int cnt=0;
    
    while(R>0){
        cnt +=1;
        R/=10;
    }
    while(cnt>0){
        
        n = N%10;
        for(int i=0;i<cnt-1;i++){
            n *=10;
        }
        cnt--;
        sum += n;
        N /=10;      
    }
    printf("%d",sum);

}