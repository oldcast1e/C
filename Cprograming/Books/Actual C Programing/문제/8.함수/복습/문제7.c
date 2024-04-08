#include  <stdio.h>
int fuc2(int x,int a,int b,int c){
    int rst = a*x*x +b*x +c ;
    return rst;
}

int main(){
    int x,a,b,c;
    scanf("%d",&x);
    scanf("%d %d %d",&a,&b,&c);
    printf("%d",fuc2(x,a,b,c));
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

