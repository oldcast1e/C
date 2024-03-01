#include  <stdio.h>
struct complex{//구조체 정의
    /* data */
    double n,i;//구조체 멤버 선언
}st1,st2;//구조체 선언

struct complex *larger(struct complex *a,struct complex *b){
    double abs_a,abs_b; 
    abs_a = (a->n)*(a->n) + (a->i)*(a->i);
    abs_b = (b->n)*(b->n) + (b->i)*(b->i);

    return abs_a>abs_b?a:b;
}
// struct complex add(struct complex a,struct complex b){//구조체 함수 정의

//     struct complex c;//구조체 선언
//     c.n = a.n + b.n;//구조체 a와 b의 정수부분을 더함
//     c.i = a.i + b.i;//구조체 a와 b의 허수부분을 더함
//     // printf("");
//     return c;//구조체 반환
// }
int main(){//메인 함수

    struct complex rst;//결과값 구조체 선언
    scanf("%lf %lf",&st1.n,&st1.i);//a구조체의 수 입력받음
    scanf("%lf %lf",&st2.n,&st2.i);//b구조체의 수 입력받음

    struct complex *rst_dir = larger(&st1,&st2);
    printf("lager : %.1lf + %.1lfi",rst_dir->n,rst_dir->i);
    // rst = add(st1,st2);//결과값 저장
    // printf("%.1lf + %.1lfi",rst.n,rst.i);//결과 출력

}
//2.3 4.5
//3.4 5.0
/*
1.2 2
-2.2 -0.3
*/