#include  <stdio.h>

int add(int x,int y){

    int c = x+y;
    return c;

}

int main(){
    
    int N,sum=0;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        sum = add(sum,i);
    }
    printf("%d",sum);

}



// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

