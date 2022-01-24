#include  <stdio.h>

int square(int x){

    int spn = 0;//줄 띄움 변수를 0으로 초기화
    for(int i=1;i<=x;i++){//입력된 x번 만큼 반복

        if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            printf("\n");//
        spn++;//줄 띄움 변수 증가

        if(i==1 || i==x){//i가 1이거나 x인 경우(print_row1)
            for(int j=0;j<x;j++){//x번 만큼 x를 출력
                printf("%d",x);//출력
            }
        }
        else{//i가 1이거나 x가 아닌 경우(print_row2)
            printf("%d",x);//첫번째로 x를 출력하고
            for(int j=0;j<x-2;j++){//x-2번 공백을 출력하고
                printf(" ");
            }
            printf("%d",x);//x를 출력
        }
    }
    return 0;//반환값 0
}

int main(){
    
    int N;
    scanf("%d",&N);
    square(N);

    
}


