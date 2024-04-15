#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* 성 공 */

/*
N개의 정수를 두 번 입력받아, 
예시와 같이 역방향으로 더하여 출력하는 프로그램을 작성하시오.
*/

int main(){
    int N; scanf("%d",&N);
    int *num1 = (int *)malloc(sizeof(int)*N);
    int *num2 = (int *)malloc(sizeof(int)*N);

    int *rst = (int *)malloc(sizeof(int)*N);
    
    for(int i=0;i<N;i++){scanf("%d",&num1[i]);}
    for(int i=0;i<N;i++){scanf("%d",&num2[i]);}

    for(int i=0;i<N;i++){rst[i] = num1[i] + num2[N-i-1];}
    for(int i=0;i<N;i++)printf("%d ",rst[i]);
} 
/*
3
1 2 3
5 10 15
*/