#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,rst=0;
    float n1,n2;
    
    scanf("%d",&a);
    
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++)if(i+j==a)printf("%d %d\n",i,j);
    }//printf("%d",rst);
 
} 
/*

*/