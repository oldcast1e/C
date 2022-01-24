#include  <stdio.h>
#include  <string.h>
struct complex{
    double real,imag;
};

struct complex add_st(struct complex *a,struct complex *b){
    /* data */
    struct complex c;
    c.real = a->real  + b->real;
    c.imag = a->imag  + b->imag;

    return c;
};


int main(){

    struct complex a,b,c;

    scanf("%lf %lf",&a.real,&a.imag);
    scanf("%lf %lf",&b.real,&b.imag);

    c = add_st(&a,&b);
    printf("%.1lf %.1lfi",c.real,c.imag);

}