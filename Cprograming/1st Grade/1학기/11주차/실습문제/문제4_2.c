#include  <stdio.h>

void print_row1(int x){//print_row1함수 정의
    for(int i=0;i<x;i++){//x번 반복하여 
        printf("%d",x);//x출력
    }
}

void print_row2(int x){//print_row2함수 정의
    printf("%d",x);//첫번째 x출력
    for(int i=0;i<x-2;i++){//x-2번 반복하여
        printf(" ");//공백을 출력하고
    }
    printf("%d",x);//두번째 x출력 
    printf("\n");//줄을 띄움
}


int main(){//main함수
    
    int N;//입력받을 N값 선언
    scanf("%d",&N);//N을 입력받고
    print_row1(N);//print_row1함수 실행
    printf("\n");//줄을 띄우고
    for(int i=0;i<N-2;i++){//N-2번 만큼 print_row2함수 실행
        print_row2(N);
    }
    print_row1(N);//이후 print_row1함수 실행

    
}


