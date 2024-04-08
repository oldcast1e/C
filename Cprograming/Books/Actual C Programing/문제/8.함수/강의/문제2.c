#include  <stdio.h>

int sum(int x,int y){

    double rst = y*(y+1)/2 - (x-1)*(x)/2;

    return rst;
}
int main(){
    
    int A,B;
    scanf("%d %d",&A,&B);
    int rst =  sum(A,B);
    printf("%d",rst);


}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

