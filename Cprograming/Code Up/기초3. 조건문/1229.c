#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    float h,w;
    
    // scanf("%d",&a);
    scanf("%f %f",&h,&w);
    float nw,ow; 
    if(h<150)nw = h- 100;
    else if(150 <= h && h < 160){ nw= (h- 150) /2 + 50; }
    else {nw = (h - 100) * 0.9;}
    // nw = (h- (float)100) * (float)0.9;
    
    ow = (w - nw) * (float)100 / nw;
    // printf(">>%f\n",ow);
    printf("%s",ow<=10.00001?"정상":ow<=20.00001?"과체중":"비만");
 
} 

/*
nw = 170 - 100 * 0.9 => 63
ow = 69.3 - 63 * 100 / 63
*/