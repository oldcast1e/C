#include  <stdio.h>

int fun2(int x,int a,int b,int c){

    int rst;
    rst = a*x*x + b*x +c;

    return rst;
}
int main(){
    
    int N,a,b,c;
    scanf("%d",&N);
    scanf("%d %d %d",&a,&b,&c);
    printf("%d",fun2(N,a,b,c));
    
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

