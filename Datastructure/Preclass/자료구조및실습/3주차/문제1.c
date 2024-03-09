#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// [ 문제 1 ] 양의 정수 N을 입력 받아, 1부터 N까지의 합을 구하는 프로그램을 작성하시오.
int add(int n, int *rst){
    if(n - 1 >= 0){
        *rst += n; n --;
        return add(n,rst);
    }
    else return *rst;
}

int main(){
    int n,rst=0; scanf("%d",&n);
    rst =  add(n,&rst);
    printf("%d",rst);
    
} 
/*

*/