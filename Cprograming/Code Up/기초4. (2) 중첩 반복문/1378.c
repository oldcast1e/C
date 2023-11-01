#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,rst=0;
    float n1,n2;
    
    scanf("%d",&a);
    
    for(int i=1;i<=a;i++){
        int cnt = 0;
        for(int j=1;j<=i;j++)cnt+=j;
        rst += cnt;
    }printf("%d",rst);
 
} 
/*

*/