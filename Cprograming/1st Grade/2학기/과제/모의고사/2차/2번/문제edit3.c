#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <math.h>

struct complex{//구조체 정의
    double val_f;//실수
    double val_c;//허수
    double val_abs;//절대값
}val[3];

struct complex add(struct complex val_1 , struct complex val_2){//함수 정의
    struct complex tmp;//임의 구조체 선언
    tmp.val_f = val_1.val_f + val_2.val_f;//실수부 저장
    tmp.val_c = val_1.val_c + val_2.val_c;//허수부 저장
    // printf("add: %lf %lf\n",tmp.val_f,tmp.val_c);
    return tmp;
}

struct complex sub(struct complex val_1 , struct complex val_2){
    struct complex tmp;
    tmp.val_f = val_1.val_f - val_2.val_f;//실수부 저장
    tmp.val_c = val_1.val_c - val_2.val_c;//허수부 저장
    // printf("sub: %lf %lf\n",tmp.val_f,tmp.val_c);
    return tmp;
}

void abs_val(struct complex *p1, struct complex *p2, struct complex *p3){
    
    p1->val_abs = sqrt((p1->val_f * p1->val_f) + (p1->val_c * p1->val_c));//절대값 저장
    p2->val_abs = sqrt((p2->val_f * p2->val_f) + (p2->val_c * p2->val_c));//절대값 저장
    p3->val_abs = sqrt((p3->val_f * p3->val_f) + (p3->val_c * p3->val_c));//절대값 저장

    struct complex max_save = *p1;//최대값을 저장할 구조체 선언
    struct complex min_save = *p2;//최솟값을 저장할 구조체 선언

    if(p2->val_abs > p1->val_abs &&  p2->val_abs > p3->val_abs) max_save = *p2;
    if(p3->val_abs > p1->val_abs &&  p3->val_abs > p2->val_abs) max_save = *p3;
    //스왑

    if(p1->val_abs < p3->val_abs &&  p1->val_abs < p2->val_abs) min_save = *p1;
    if(p3->val_abs < p2->val_abs &&  p3->val_abs < p1->val_abs) min_save = *p3;
    //스왑

    *p1 = max_save;
    *p2 = min_save;   
    //값 저장 

}

int main(){
    for(int i=0;i<3;i++) scanf("%lf %lf",&val[i].val_f,&val[i].val_c);
    //값을 입력받고
    abs_val(&val[0],&val[1],&val[2]);
    //절대값 구하기

    struct complex cal_1 = add(val[0],val[1]);//결과 저장(1)
    struct complex cal_2 = sub(val[0],val[1]);//결과저장(2)
    printf("%.1lf%+.1lfi\n",cal_1.val_f,cal_1.val_c);//출력
    printf("%.1lf%+.1lfi",cal_2.val_f,cal_2.val_c);//출력
}
/*
2.3 0.0
3.4 5.0
1.4 -7.2

*/