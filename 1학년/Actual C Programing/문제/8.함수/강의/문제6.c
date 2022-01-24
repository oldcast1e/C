#include  <stdio.h>

int fun1(int x){

    int rst;
    rst = 2*x*x - 5*x +1;

    return rst;
}
int main(){
    
    int N;
    scanf("%d",&N);
    printf("%d",fun1(N));
    
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

