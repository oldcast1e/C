/*
[문제1] N(3≤N≤100)개의정수로이루어진수열X를
“뒤집기정보”에의해변환한최종 결과를 출력하는 프로그램을 작성하시오. 
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void swap(int *num,int *a,int *b){
    int tmp,rep = (*b-*a)%2==0?(*b-*a)/2:(*b-*a)/2+1;
    //printf(">>(*a + *b)/2/2 = %d\n",(*a + *b)/2);
    for(int i=0;i<rep;i++){
        tmp = num[*a+i]; 
        num[*a+i] = num[*b-i];
        num[*b-i] =tmp;
    }
}


int main(){
    int n,rpt,a,b; 
    scanf("%d",&n);
    signed int *num = (int *)malloc(sizeof(int)*n+1);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);

    scanf("%d",&rpt);

    for(int i=0;i<rpt;i++){
        scanf("%d %d",&a,&b);
        swap(num,&a,&b);
        // for(int i=0;i<n;i++) printf(" %d",num[i]); printf("\n");
    }
    for(int i=0;i<n;i++) printf(" %d",num[i]);

    

    
} 
/*
6
30 10 20 0 40 50 
2
1 2 0 3


30 20 10 0 40 50 

10
3 81 9 12 0 -9 36 33 91 10
3
3 7 4 5 0 4

-9 33 9 81 3 36 0 12 91 10
 -9 33 9 81 3 36 0 12 91 10

*/