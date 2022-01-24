#include  <stdio.h>
int main() 
{
    int n,min;
    scanf("%d",&n);
    min = n;
    while (n!=0)
    {   
        scanf("%d",&n);
        if(n<min)
            min = n;
    }
    printf("%d ",min);

}