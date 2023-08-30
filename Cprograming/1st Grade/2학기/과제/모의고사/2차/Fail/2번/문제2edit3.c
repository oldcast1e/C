#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <math.h>
struct complex{
    /* data */
    double val_f;
    double val_c;
    double val_ab;
}cal[3];


struct complex add(struct complex val_1, struct complex val_2){
    struct complex tmp;
    tmp.val_f = val_1.val_f + val_2.val_f;
    tmp.val_c = val_1.val_c + val_2.val_c;

    return tmp;
}

struct complex sub(struct complex val_1, struct complex val_2){
    struct complex tmp;
    tmp.val_f = val_1.val_f - val_2.val_f;
    tmp.val_c = val_1.val_c - val_2.val_c;
    return tmp;
}

void abs_val(struct complex *p1, struct complex *p2, struct complex *p3){

    p1->val_ab = sqrt((p1->val_f * p1->val_f) + (p1->val_c *p1->val_c));//절대값
    p2->val_ab = sqrt((p2->val_f * p2->val_f) + (p2->val_c *p2->val_c));//절대값
    p3->val_ab = sqrt((p3->val_f * p3->val_f) + (p3->val_c *p3->val_c));//절대값
    //각 구조체 변수에 절대값 저장
    double max,min;
    int max_index,min_index;
    if(p1->val_ab > p2->val_ab) max_index = 1;
    else{max_index = 2;}
    if(p1->val_ab > p3->val_ab) max_index = 1;
    else{max_index = 3;}
    if(p2->val_ab > p3->val_ab) max_index = 2;
    else{max_index = 3;}

    if(p1->val_ab < p2->val_ab) min_index = 1;
    else{min_index = 2;}
    if(p1->val_ab < p3->val_ab) min_index = 1;
    else{min_index = 3;}
    if(p2->val_ab < p3->val_ab) min_index = 2;
    else{min_index = 3;}


    if(max_index == 1){//제일 큰 수가 1번일때

    }
    else if(max_index == 2){//제일 큰 수가 2번일때

    }
    else if(max_index == 3){//제일 큰 수가 3번일때

    }

    if(min_index == 1){

    }
    else if(min_index == 2){

    }
    else if(min_index == 3){

    }



}

int main(){
    //절대 값이 가장 큰 복소수와 절대 값이 가장 작은 복소수 의 합과 차
    double max,min;
    struct complex *p1 = &cal[0];
    struct complex *p2 = &cal[1];
    struct complex *p3 = &cal[2];

    for(int i=0;i<3;i++)
        scanf("%lf %lf",&cal[i].val_f,&cal[i].val_c);
    abs_val(p1,p2,p3);

    printf("%lf | %+lf\n",p1->val_ab,p2->val_ab);


    //절대 값이 가장 큰 복소수와 절대 값이 가장 작은 복소수 의 
    //합과 차를 구하여 출력
    // struct complex cal1 = sub(*p1,*p2);
    // struct complex cal2 = sub(*p1,*p2);

    // printf("%+.1lf %+.1lf\n",cal1.val_f,cal1.val_c);
    // printf("%+.1lf %+.1lf\n",cal2.val_f,cal2.val_c);
}
/**

2.3 4.5  
3.4 5.0  
-1.4 7.2 

 */