#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
[ 문제 1 ] 양의 정수 N을 입력 받아, 
    1부터 N까지의 합을 구하는 프로그램을 작성하시오.
*/

void sum_fuc(int n, int *sum){
    if(n > 0){
        *sum += n;
        n --;
        return sum_fuc(n, sum);
    }
}

// int sum_fuc(int n){
//     printf("n = %d\n",n);
//     if(n > 0){
//         n --;
//         return n;
//     }
//     return 0;
// }

int main(){
    int n; scanf("%d",&n);
    int sum  = 0;
    sum_fuc(n,&sum);
    printf("%d",sum);
    // printf("%d",result);



} 
