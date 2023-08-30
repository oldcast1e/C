#include  <stdio.h>
int main(){

    int n,k;//15/9
    scanf("%d",&n);
    printf("%d is a multiple of %d",n,k=(n%15==0?15:(n%5==0?5:(n%3==0?3:n))));
}