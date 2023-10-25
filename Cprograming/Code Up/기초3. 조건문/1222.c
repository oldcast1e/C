#include<stdio.h>
int main(){int a,b,c;scanf("%d %d %d",&a,&b,&c);while(a<90){b+=1;a+=5;}printf("%s",b>c?"win":(b==c?"same":"lose"));} 
