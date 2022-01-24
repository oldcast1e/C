#include  <stdio.h>

int fun2(int x,int a,int b,int c){

    int rst;
    rst = a*x*x + b*x +c;

    return rst;
}
int main(){
    
    int N,a,b,c;
    int a2,b2,c2;
    scanf("%d",&N);
    scanf("%d %d %d",&a,&b,&c);
    scanf("%d %d %d",&a2,&b2,&c2);
    printf("%d",fun2(fun2(N,a,b,c),a2,b2,c2));
    
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

