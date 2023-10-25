#include<stdio.h>
int main(){
    float a,b,max,cnt=1;scanf("%f %f",&a,&b);
    max=(a+b>max)?(a+b):max;max=(a-b>max)?(a-b):max;
    max=(b-a>max)?(b-a):max;max=(a*b>max)?(a*b):max;
    max=(a/b>max)?(a/b):max;max=(b/a>max)?(b/a):max;
    for(int i=0;i<b;i++)cnt*=a;max=(cnt>max)?(cnt):max;cnt=1;
    for(int i=0;i<a;i++)cnt*=b;max=(cnt>max)?(cnt):max;printf("%0.6f",max);
} 