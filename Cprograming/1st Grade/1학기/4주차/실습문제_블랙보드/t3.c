#include  <stdio.h>

int main() 
{
   int N,M;
   scanf("%d %d",&N,&M);//N,M을 선언하고 값을 입력받는다.
   printf("%d\n",N>M?N/M:M/N);//N보다 M이 작으면 N/M 아닌경우 M/N을 한다.
   printf("%d\n",N>M?N%M:M%N);//N보다 M이 작으면 N%M 아닌경우 M%N을 한다.



}