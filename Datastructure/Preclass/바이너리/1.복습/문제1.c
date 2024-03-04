#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/**
하나의 양의 정수 X을 입력 받아 다음 수식의 결과를 출력하는 프로그램을 작성하시 오.
1 + (1+2) + (1+2+3) + (1+2+3+4) + ... + (1+2+...+X)
 */

int sum(int n){
    int rst =0;
    for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)rst += j;
    return rst;
}
int main(){
    int N;
    scanf("%d",&N);
    
    printf("%d",sum(N));

}