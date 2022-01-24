#include  <stdio.h>
int main(){

    double n,m,k,sum=0,avg;
    int max =-1,min=101;
    scanf("%lf %lf %lf",&n,&m,&k);
    sum += (n+m+k);
    avg = sum/3;
    max = (n>m&&n>k?n:(m>n&&m>k?m:k>n&&k>m?k:max));
    min = (n<m&&n<k?n:(m<n&&m<k?m:k<n&&k<m?k:min));
    if(avg>=90){
        printf("A\n");
    }
    else if(avg>=80){
        printf("B\n");
    }
    else if(avg>=70){
        printf("C\n");
    }
    else if(avg>=60){
        printf("D\n");
    }
    else
        printf("F\n");
    printf("max: %d\n",max);
    printf("min: %d",min);



    
}