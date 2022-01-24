#include  <stdio.h>
int main() 
{
    int n,m,i,j;
    scanf("%d",&n);
    while(n>0){
        scanf("%d",&m);
        if(m%3==0){
            printf("꽝\n");
            continue;
        }
        
        n--;
        printf("남은 횟수: %d\n",n);
        for(j=0;j<n;j++){
            printf("벌칙\n");
        }
    }

}