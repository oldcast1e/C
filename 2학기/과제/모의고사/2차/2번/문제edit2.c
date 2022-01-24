#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <math.h>

struct complex{
    double val_f;
    double val_c;
    double val_abs;
}val[3];

struct complex add(struct complex val_1 , struct complex val_2){
    struct complex tmp;
    tmp.val_f = val_1.val_f + val_2.val_f;
    tmp.val_c = val_1.val_c + val_2.val_c;
    // printf("add: %lf %lf\n",tmp.val_f,tmp.val_c);
    return tmp;
}

struct complex sub(struct complex val_1 , struct complex val_2){
    struct complex tmp;
    tmp.val_f = val_1.val_f - val_2.val_f;
    tmp.val_c = val_1.val_c - val_2.val_c;
    // printf("sub: %lf %lf\n",tmp.val_f,tmp.val_c);
    return tmp;
}

void abs_val(struct complex *p1, struct complex *p2, struct complex *p3){
    struct complex *tmp[3];
    tmp[0] = p1;tmp[1] = p2;tmp[2] = p3;
    double max,min;
    int max_index,min_index;
    for(int i=0;i<3;i++){
        tmp[i]->val_abs = sqrt((tmp[i]->val_f * tmp[i]->val_f) + (tmp[i]->val_c * tmp[i]->val_c));
    }

    for(int i=0;i<3;i++){
        if(i==0){
            max = tmp[0]->val_abs;
            max_index = i;
        }
        else{
            if(tmp[i]->val_abs > max){
                max = tmp[i]->val_abs;
                max_index = i;
            }
            
        }
    }//max

    for(int i=0;i<3;i++){
        if(i==0){
            min = tmp[0]->val_abs;
            min_index = i;
        }
        else{
            if(tmp[i]->val_abs < min){
                min = tmp[i]->val_abs;
                min_index = i;
            }
            
        }
    }//min
    p1 = tmp[max_index];//tmp[2] (p3)
    p2 = tmp[min_index];//tmp[0] (p1)

    struct complex cal_1 = add(*p1,*p2);
    struct complex cal_2 = sub(*p1,*p2);
    printf("%.1lf%+.1lfi\n",cal_1.val_f,cal_1.val_c);
    printf("%.1lf%+.1lfi",cal_2.val_f,cal_2.val_c);
}

int main(){
    for(int i=0;i<3;i++) scanf("%lf %lf",&val[i].val_f,&val[i].val_c);
    abs_val(&val[0],&val[1],&val[2]);
}
/**

2.3 4.5
3.4 5.0
-1.4 7.2

 */