#include  <stdio.h>

int sum(int x){

    int rst = 0;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=i;j++){
            rst += j;
    }
    }
    return rst;
}
int main(){
    
    int X;
    scanf("%d",&X);
    printf("%d",sum(X));
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

