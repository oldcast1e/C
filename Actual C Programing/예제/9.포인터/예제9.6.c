#include  <stdio.h>
int main(){
    
    int *p1 = NULL;
    char *p2 = NULL;
    printf("%p %p\n",p1,p2);

    p1 ++,p2 ++;
    printf("%p %p\n",p1,p2);

    p1 +=2 ,p2 +=2;
    printf("%p %p",p1,p2);
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

