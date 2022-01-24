#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//정수 n,m을 입력하고 nxm의 정사각형을 만들어라
int main(){
    int n,m;
    printf("정수 n,m을 입력하세요: ");scanf("%d %d",&n,&m);
    printf("직사각형을 출력합니다.\n");printf("높이: %d\n너비: %d\n",n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) printf("*");
        printf("\n");
    }
}
