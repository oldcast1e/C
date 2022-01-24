#include  <stdio.h>
int main() 
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("   ");
    }

    for(i=1;i<=31;i++){
        printf("%3d",i);
        if((n+i)%7==0){
            printf("\n");
        }
    }

}