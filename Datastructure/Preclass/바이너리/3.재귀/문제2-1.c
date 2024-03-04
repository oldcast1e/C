#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/*양의 정수를 입력 받아, 각 자리의 수를 높은 자릿수부터 차례로 출력하는 프로그램을 작성하시오.*/
void decimal(int n){
    int tmp=n,cnt=0,dev=1,rst;
    while(tmp > 0){tmp /= 10;cnt ++;}
    // printf("tmp = %d",cnt);
    for(int i=0;i<cnt-1;i++) dev *=10;
    rst = (n- (n%dev))/dev;
    printf("%d\n",rst);
    n = n- dev;
    if(n > 0) decimal(n);
    // if(n > 0){
    //     printf()
    // }
    //3408 -> 4자리수. 3408 - (1000으로 나눴을때 나머지) = 3000
    //08   -> 2자리수. 08   - (  10으로 나눴을 때 나머지==8) = 0
    //3000을 1000으로 나누면 3
}
int main(){
    int n;scanf("%d",&n);
    decimal(n);

}