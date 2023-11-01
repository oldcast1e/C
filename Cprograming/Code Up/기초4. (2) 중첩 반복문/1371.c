#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,a,b,c,d,cnt=0;
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
			for(int a=0;a<n-i;a++)printf(" ");printf("*");
			
			for(int c=0;c<2*i;c++)printf(" ");
			
			//for(int b=0;b<i;b++)printf(" "); 
			printf("*\n");
    }
    //for(int i=0;i<cnt;i++)
		for(int i=n-1;i>=0;i--){
			for(int a=0;a<n-i;a++)printf(" ");printf("*");
			
			for(int c=0;c<2*i;c++)printf(" ");
			
			//for(int b=0;b<i;b++)printf(" "); 
			printf("*\n");
    }	
 
} 
/*
5

    **
   *--*
  *----*
 *------*
*        *
*        *
 *      *
  *    *
   *  *
    **
*/