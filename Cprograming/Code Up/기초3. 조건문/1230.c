#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int num[3],key = 0;
    scanf("%d %d %d",&num[0],&num[1],&num[2]);
    for(int i=0;i<3;i++) if(170>=num[i]){printf("CRASH %d",num[i]);key = 1;break;}
    if(key == 0)printf("PASS");
    // scanf("%d %d %d %d",&a,&b,&c,&d);
    // printf("%d",1<<3);
    // printf("%f",cnt);
 
} 