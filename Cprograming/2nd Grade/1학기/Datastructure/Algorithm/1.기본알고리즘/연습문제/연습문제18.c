#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//아래를 향하고 각 층은 1~n으로 이루어진 n단의 피라미드를 출력하는 프로그램을 작성하라.
void spira(int n){
    int num = 1;
    for(int i=n;i>=1;i--){
        for(int k=0;k<n-i;k++)printf(" ");
        for(int j=0;j<2*i-1;j++) printf("%d",num);printf("\n");
        num ++;
    }
}
int main(){
    int n;
    printf("정수 n을 입력하세요: ");scanf("%d",&n);
    spira(n);
}
