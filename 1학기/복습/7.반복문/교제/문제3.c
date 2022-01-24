#include  <stdio.h>
int main(){

    int n,rst = 0;
    scanf("%d",&n);
    while(n>0){
        rst += n%10;
        rst *=10;
        n /=10;
    }
    printf("%d",rst/10);


}
