#include  <stdio.h>
int add(int x,int y){

    int rst = x+y;
    return rst;
}

int main(){

    int n,rst=0;
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        rst = add(i,rst);
    }
    printf("%d",rst);
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

