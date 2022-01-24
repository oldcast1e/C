#include  <stdio.h>
int main() 
{
    int n,m;
    scanf("%d %d",&n,&m);

        for(int j=1;j<=9;j++){
            for(int k=n;k<=m;k++){//3,5
                printf("%d*%d=%d ",k,j,k*j);
            }
            printf("\n");
            
        }
    


}