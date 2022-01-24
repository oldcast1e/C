#include  <stdio.h>
int main(){
    
    int num1,num2, *p = &num1;
    *p = 3000;
    num2 = *p;
    p = &num2;
    *p = *p - 1000;
    num1 = *p*2;

    printf("값: num1 = %d num2 = %d p=%p\n",num1,num2,p);
    printf("주소: num1 = %p num2 = %p p=%p\n",&num1,&num2,&p);
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

