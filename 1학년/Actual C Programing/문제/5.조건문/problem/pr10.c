#include<stdio.h>
int main(){

    int l,e,m;
    scanf("%d %d %d",&l,&e,&m);   
    double avg = (l+m+e)/3;

    if(avg>=91.5)
        printf("A");
    else if(avg>=85.5)
        printf("B");
    else if(avg>=80.5)
        printf("C");
    else
        printf("F");

    if(l==100 || e==100 || m==100)
        printf("Good");
    if(l<=60 || e<=60 || m<=60)
        printf("Bad");

}