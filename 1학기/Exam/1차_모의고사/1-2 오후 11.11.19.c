#include  <stdio.h>
int main(){

    double a,b,c,d,e;
    double avg=0;
    double min= 101;

    int cnt=0;
    scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&d,&e);
    if(a<40)
        cnt++;
    if(b<40)
        cnt++;
    if(c<40)
        cnt++;
    if(d<40)
        cnt++;
    if(e<40)
        cnt++;
    


    if(a>100 ||a<0 || b>100 ||b<0 || c>100 ||c<0 || d>100 ||d<0 || e>100 ||e<0){
        printf("Invalid");
    }
    else{
        avg +=(a+b+c+d+e)/5;
    if(avg>=90){
        if(cnt>=3){
            printf("F");
        }
        else
            printf("A+\n");
    }
    else if(avg>=75){
        if(cnt>=3){
            printf("F");
        }
        else
            printf("A\n");
    }
    else if(avg>=65){
        if(cnt>=3){
            printf("F");
        }
        else
            printf("B+\n");
    }
    else if(avg>=50){
        if(cnt>=3){
            printf("F");
        }
        else
            printf("B\n");
    }
    else
        printf("F");
    
    printf("avg=%.2f ",avg);
    if(a<b && a<c && a<d && a<e)
        printf("min=%.0f",a);
    else if(b<a && b<c && b<d && b<e)
        printf("min=%.0f",b);
    else if(c<a && c<b && c<d && c<e)
        printf("min=%.0f",c);
    else if(d<a && d<b && d<c && d<e)
        printf("min=%.0f",d);
    else if(e<b && e<c && e<d && e<a)
        printf("min=%.0f",e);
    }
    

    
   
    
}