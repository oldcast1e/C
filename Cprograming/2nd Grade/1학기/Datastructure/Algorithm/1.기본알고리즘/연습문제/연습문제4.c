#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//세 정수의 중앙값을 찾는 알고리즘
int centerval(int a,int b,int c){
    int rst = a;
    if(a>b && a>c) rst = (b>c)?b:c;//3번
    else if(b>a && b>c) rst = (a>c)?a:c;//5번
    else rst = (a>b)?a:b;//5번

    return rst;
}
int main(){
    int val[3] = {},rst;
    printf("세 정수의 중앙값을 구합니다.\n");
    for(int i=0;i<3;i++){printf("%c의 값: ",(97+i));scanf("%d",&val[i]);}
    rst = centerval(val[0],val[1],val[2]);

    printf("중앙값은 %d 입니다.",rst);

}
