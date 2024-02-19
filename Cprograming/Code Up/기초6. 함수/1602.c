#include<stdio.h>
float ABS(float a){
    return(float)(a<0?a*=-1:a);
}

int main(){
    float n; scanf("%f",&n);

    n = ABS(n);
    if((int)n != n)printf("%g",n);
    else printf("%d",(int)n);
    // int front  = n/1;
    // float back = n-front;
    // // printf("%f",ABS(n));
    // printf("%d %f",front,back);

    // printf("%f %f",n/1,n);

}