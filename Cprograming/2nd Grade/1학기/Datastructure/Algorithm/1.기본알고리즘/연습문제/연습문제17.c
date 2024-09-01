#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//n단의 피라미드를 출력하는 프로그램을 작성하라.
//단 i열의 *는 (2*i - 1)개이다.
void spira(int n){
    for(int i=1;i<=n;i++){
        for(int k=0;k<n-i;k++)printf(" ");
        for(int j=0;j<2*i-1;j++) printf("*");printf("\n");
    }
}
int main(){
    int n;
    printf("정수 n을 입력하세요: ");scanf("%d",&n);
    spira(n);
}
