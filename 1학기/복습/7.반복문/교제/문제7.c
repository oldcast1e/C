#include <stdio.h>
int main()
{
   int n,m;
   scanf("%d %d",&n,&m);

   for(int i=1;i<=9;i++){
       for(int j=n;j<=m;j++){
           printf("%dx%d=%d ",j,i,i*j);
       }
       printf("\n");
   }

   return 0;
}