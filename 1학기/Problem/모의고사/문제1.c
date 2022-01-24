#include  <stdio.h>
int main(){

    double n,m,a,b,sum;
    scanf("%lf %lf",&n,&m);
    a = n*0.4;
    b = m *0.6;
    sum += (a+b);
    if(sum>=85.5)
        printf("A");
    else if(sum>=75.5)
        printf("B");
    else if(sum>=60)
        printf("C");
    else 
        printf("F");

    if(sum>=60 ||m>=90)
        printf(" PASS");
    else
        printf(" FAIL");    
    
}
