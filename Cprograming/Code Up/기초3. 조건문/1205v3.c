#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    // float ipt[2]; scanf("%d %d",&ipt[0],&ipt[1]);
    float a,b; scanf("%f %f",&a,&b);
    float max = a+b;
    max = (a+b>max)?(a+b):max;
    max = (a-b>max)?(a-b):max;
    max = (a*b > max)?(a*b):max;
    max = (a/b > max)?(a/b):max;
    float cnt = 1;
    for(int i=0;i<b;i++) cnt*=a;
    max = (cnt > max)?(cnt):max;
    // max = (((int)a<<(int)b) > max)?((int)a<<(int)b):max;

    max = (a+b>max)?(b+a):max;
    max = (b-a>max)?(b-a):max;
    max = (a*b>max)?(a*b):max;
    max = (b/a>max)?(b/a):max;
    cnt = 1;
    for(int i=0;i<a;i++) cnt*=b;
    max = (cnt > max)?(cnt):max;


    printf("%0.6f",max);
 
} 