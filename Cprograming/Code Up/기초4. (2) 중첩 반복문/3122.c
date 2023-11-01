#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    float n1,n2;
    
    scanf("%d",&a);
    for(int i=0;i<a-1;i++){//가운데 일자 *전까지
        for(int j=0;j<a-1-i;j++)printf(" ");
        for(int k=0;k<(2*i+1);k++)printf("*");
        for(int j=0;j<a-1-i;j++)printf(" ");printf("\n");
    }
	for(int r=0;r<2*a-1;r++)printf("*");printf("\n");
    
	for(int i=a-1-1;i>=0;i--){//가운데 일자 *전까지
        for(int j=0;j<a-1-i;j++)printf(" ");
        for(int k=0;k<(2*i+1);k++)printf("*");
        for(int j=0;j<a-1-i;j++)printf(" ");printf("\n");
    }
 
} 
/*
3
*뒤에도 공백을 채워 출력

  *  
 *** 
*****
 *** 
  *  
*/