#include  <stdio.h>
int main(){

    int n,rst=0;
    int a=0,b=0;
    scanf("%d",&n);
    while(n>0){
        rst += n%10;
        n/=10;
        if(n<=0)
            break;
        rst*=10;
        
    }
    printf("%d\n",rst);
    for(int i=1;i<=rst;i++){

        if(i%2==0)
            a +=1;
        if(i%3==0)    
            b +=1;
    }
    printf("%d %d",a,b);
    
}