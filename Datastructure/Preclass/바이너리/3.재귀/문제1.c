#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <math.h>
/*양의 정수 N을 입력 받아, 1부터 N까지의 합을 구하는 프로그램을 작성하시오.*/
void function(int n,int *prst){
    if(n>0){
        *prst += n;
        n-=1;
        function(n,prst);
    }
}
int main(){
    int N,rst=0,*prst = &rst;scanf("%d",&N);
    function(N,prst);
    printf("%d",*prst);
}
