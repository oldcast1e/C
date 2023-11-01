#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n[1000],a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)scanf("%d",&n[i]);
    for(int i=a-1;i>=0;i--)printf("%d ",n[i]);
 
} 
/*

*/