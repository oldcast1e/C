#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    long int a,b=0,c,d,cnt=0,i,j;    
    scanf("%ld",&a);
    for( i=a;i>=1;i--){
        for( j=1;j<=i;j++) if(j*j == i){printf("%ld %ld",cnt,j); b=1;break;}
        if(b==1) break;
        cnt ++;
    }//if(b==0)printf("%ld",a);
} 

/*
55565478
50000001
1001
2001
*/