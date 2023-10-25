#include<stdio.h> 
int main(){int a,b,c;scanf("%d %d %d",&a,&b,&c);printf("%s",a>b-c?"do not advertise":(a==b-c?"does not matter":"advertise"));} 