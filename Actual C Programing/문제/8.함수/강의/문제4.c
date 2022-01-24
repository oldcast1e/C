#include  <stdio.h>

int print_row1(int x){
    for(int i=0;i<x;i++){
        printf("%d",x);
    }

    return 0;
}

int print_row2(int x){
    for(int j=0;j<x-2;j++){
        printf("%d",x);
        for(int i=0;i<x-2;i++){
            printf(" ");
        }
        printf("%d\n",x);
    }
    return 0;
}

int main(){
    
    int N;
    scanf("%d",&N);
    print_row1(N);
    printf("\n");
    print_row2(N);
    print_row1(N);

    
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

