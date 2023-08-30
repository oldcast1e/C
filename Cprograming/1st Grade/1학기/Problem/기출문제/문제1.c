#include  <stdio.h>
int main(){

    double N,M,n,m;
    double avg1,avg2,max;
    scanf("%lf %lf %lf %lf",&N,&M,&n,&m);
    avg1 = (N+M)/2;
    avg2 = (n+m)/2;
    max = (avg1>avg2?avg1:avg2);
    if(N<=60 ||M<=60 ||n<=60 ||m<=60){
        printf("F");
    }
    else {
        if(max>=90){
        printf("A+");
    }
    else if(max>=80){
        printf("A");
    }
    else if(max>=70){
        printf("B+");
    }
    else if(max>=60){
        printf("B");
    }
    }


}