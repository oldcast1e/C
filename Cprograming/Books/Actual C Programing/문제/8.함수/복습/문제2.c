#include  <stdio.h>

int sum(int x){
    int rst = x*(x+1)/2;
    return rst;
}
int main(){
    int n,m;
    int N,M;
    scanf("%d %d",&n,&m);
    N = sum(n)-n;
    M = sum(m);
    printf("%d",M-N);
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

