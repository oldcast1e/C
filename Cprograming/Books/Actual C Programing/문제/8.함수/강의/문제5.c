#include  <stdio.h>

int printf_triangle(n){

    for(int i=0;i<n;i++){
            for(int j=0;j<i+1;j++){
                printf("*");
            }
            printf("\n");
        }
    return 0;
}
int main(){

    int n;
    while(1){
        scanf("%d",&n);
        if(n<=0) break;
        printf_triangle(n);   
    }
    
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

