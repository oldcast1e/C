#include  <stdio.h>
int main(){

    int n,m,rvs=0,rst=0;
    scanf("%d",&n);
    m = n;

    rvs += n%10;
    n/=10;
    rvs *=10;
    rvs += n%10;
    n/=10;
    rvs *=10;
    rvs += n%10;
    n/=10;
    rvs *=10;
    rvs += n%10;
    n/=10;


    rst = m - rvs;
    printf("%d",rst=(rst>0?rst:rst*(-1)));

    
}