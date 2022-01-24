#include  <stdio.h>
int main() 
{
    int n,sum=0;
    scanf("%d",&n);
    int min = n,max=n;
    while(n!=0){
        sum +=n;
        min = (min>n?n:min);
        max = (max<n?n:max);
        scanf("%d",&n);
        if(n==0)
            break;
    }
    printf("합: %d\n",sum);
    printf("최솟값: %d\n",min);
    printf("최댓값: %d",max);


}