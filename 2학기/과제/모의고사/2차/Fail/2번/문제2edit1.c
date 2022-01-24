#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <math.h>
struct complex{
    /* data */
    double val_f;
    double val_c;
    double val_ab;
    //실수부를 나타내는 실수형 변수, 
    //허수부를 나타내는 실수형 변수, 
    //절대값을 나타내는 실 수형 변수
    /**
     
    
     */
    
}cal[3];


struct complex add(struct complex val_1, struct complex val_2){
    struct complex tmp;
    tmp.val_f = val_1.val_f + val_2.val_f;
    tmp.val_c = val_1.val_c + val_2.val_c;

    return tmp;
}

struct complex sub(struct complex val_1, struct complex val_2){
    struct complex tmp;
    return tmp;
}

void abs_val(struct complex *p1, struct complex *p2, struct complex *p3){
//p1, p2, p3이 가리키는 구조체 변수의 절대 값을 계산하고, 
//p1이 가리키는 변수에 절대값이 가장 큰 복소수를, 
//p2가 가리키는 변수에 절대 값이 가장 작은 복소수를 저장한다.

    p1->val_ab = sqrt(p1->val_f * p1->val_f) + (p1->val_c *p1->val_c);
    p2->val_ab = sqrt(p2->val_f * p2->val_f) + (p2->val_c *p2->val_c);
    p3->val_ab = sqrt(p3->val_f * p3->val_f) + (p3->val_c *p3->val_c);

    double max = p1->val_ab,min = p1->val_ab;
    int max_index = 0,min_index = 0;
    if(p2->val_ab > max) { max  = p2->val_ab; max_index = 1;}
    if(p3->val_ab > max) {max  = p3->val_ab;max_index = 2;}

    if(p2->val_ab < min){ min  = p2->val_ab; min_index = 1;}
    if(p3->val_ab < min) {min  = p3->val_ab;min_index=2;}

    switch (max_index){
    case 0:
        /* code */
        break;
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;

    }


    
}

int main(){
    //절대 값이 가장 큰 복소수와 절대 값이 가장 작은 복소수 의 합과 차
    struct complex *p1 = &cal[0];
    struct complex *p2 = &cal[1];
    struct complex *p3 = &cal[2];

    for(int i=0;i<3;i++)
        scanf("%lf %lf",&cal[i].val_f,&cal[i].val_c);
    abs_val(p1,p2,p3);
    //절대 값이 가장 큰 복소수와 절대 값이 가장 작은 복소수 의 
    //합과 차를 구하여 출력

    printf("%+.1lf %+.1lf",p1->val_ab,p2->val_ab);
}
/**
세 개의 복소수를 입력받고, 
절대 값이 가장 큰 복소수와 절대 값이 가장 작은 복소수 의 합과 차를 구하여, 
아래 출력예시와 같이 ± 형태로 출력하는 프로그램을  작성 하시오. 단, a와 b는 소수점 첫째자리까지 출력한다.

- 복소수를 표현하는 complex 구조체를 정의하여 사용하시오.
◦ 실수부를 나타내는 실수형 변수, 허수부를 나타내는 실수형 변수, 절대값을 나타내는 실 수형 변수
힌트1) 복소수 a+bi의 절대값 계산은    의 공식으로 계산되며, 절대 값 비교 시에는    으로도 비교 가능하다.
(   계산 시, #include<math.h> 선언 후 sqrt() 함수사용)
힌트2) double형 실수 입력은 scanf(“%lf”, ...)를, float형 실수 입력은 scanf(“%f”, ...)를 사용한다.
힌트3) 실수 출력 시 printf(“%+.1f”, ...)를 사용하면, 양수인 경우에는 +, 음수인 경우에는 – 기 호가 숫자 앞에 표시된다. 
0인 경우에는 +0.0으로 표시된다.

2.3 4.5  
3.4 5.0  
-1.4 7.2 

 */