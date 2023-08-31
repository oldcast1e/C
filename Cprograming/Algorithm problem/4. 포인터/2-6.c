#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int num = 10;
    int *pnum = &num;

    //실제 num의 메모리 주소와 실제값
    printf("num의 메모리 주소: 0x%p | num의 실제값: %d\n",&num,num);
    //실제 pnum의 메모리 주소와 실제값
    printf("pnum의 메모리 주소: 0x%p | pnum의 실제값: 0x%p\n",&num,num);

    //pnum이 가리키는 곳의 값과 num의 값
    printf("pnum이 가리키는 곳의 값: %d | num의 값: %d\n",*pnum,num);
    //pnum의 메모리 주소와 실제값
    printf("pnum의 메모리 주소: 0x%p | pnum의 주소값: 0x%p |pnum의 실제값: %d",&pnum,pnum,*pnum);
}
}