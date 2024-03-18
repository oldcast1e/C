#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*[ 문제 1 ] 양의 정수 N을 입력 받아, 
1부터 N까지의 합을 구하는 프로그램을 작성하시오.*/
int sum = 0;
int add(int n){
    sum += n;
    if(n>0) {
        n --;
        add(n);
    }

    return sum;
}

int main(){
    int n; scanf("%d",&n);
    printf("%d",add( n));

    
} 
/*

*/