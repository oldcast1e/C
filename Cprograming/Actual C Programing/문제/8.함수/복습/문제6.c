#include  <stdio.h>
int fuc1(int n){
    int rst = 2*n*n -5*n +1;
    return rst;
}

int main(){
    int n;scanf("%d",&n);
    printf("%d",fuc1(n));
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

